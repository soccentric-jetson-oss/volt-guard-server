#include <iostream>
#include <grpcpp/grpcpp.h>
#include <volt_guard.grpc.pb.h>

class VGImpl final : public voltguard::VoltGuard::Service {
    grpc::Status SetPowerMode(grpc::ServerContext*, const voltguard::PowerMode* req, voltguard::ModeResponse* resp) override {
        std::cout << "Set mode " << req->mode() << " " << req->power_mw() << "mW\n";
        resp->set_success(true); return grpc::Status::OK;
    }
    grpc::Status GetPowerMode(grpc::ServerContext*, const voltguard::Empty*, voltguard::PowerMode* resp) override {
        resp->set_mode(1); resp->set_power_mw(15000); return grpc::Status::OK;
    }
    grpc::Status GetSensors(grpc::ServerContext*, const voltguard::Empty*, voltguard::SensorData* resp) override {
        resp->set_temp_celsius(45); resp->set_voltage_mv(12000); resp->set_current_ma(800); resp->set_power_mw(9600);
        return grpc::Status::OK;
    }
    grpc::Status HealthCheck(grpc::ServerContext*, const voltguard::Empty*, voltguard::HealthResponse* resp) override {
        resp->set_status("SERVING"); resp->set_version("0.1.0"); return grpc::Status::OK;
    }
};

int main() {
    VGImpl svc; grpc::ServerBuilder b;
    b.AddListeningPort("0.0.0.0:50055", grpc::InsecureServerCredentials());
    b.RegisterService(&svc); auto s = b.BuildAndStart();
    std::cout << "Volt Guard on :50055\n"; s->Wait();
}
