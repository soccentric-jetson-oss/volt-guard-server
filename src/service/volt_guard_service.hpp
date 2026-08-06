// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SoC Centric LLC
//
// volt_guard_service.hpp - gRPC service for Volt Guard
//
/// @brief Declares VoltGuardServiceImpl implementing power management
///        and sensor monitoring RPCs.

#pragma once

#include <volt_guard.grpc.pb.h>
#include <grpcpp/grpcpp.h>

namespace voltguard {

class VoltGuardServiceImpl final : public VoltGuard::Service {
public:
    grpc::Status SetPowerMode(grpc::ServerContext* context,
                              const PowerMode* request,
                              ModeResponse* response) override;

    grpc::Status GetPowerMode(grpc::ServerContext* context,
                              const Empty* request,
                              PowerMode* response) override;

    grpc::Status GetSensors(grpc::ServerContext* context,
                            const Empty* request,
                            SensorData* response) override;

    grpc::Status HealthCheck(grpc::ServerContext* context,
                             const Empty* request,
                             HealthResponse* response) override;
};

} // namespace voltguard
