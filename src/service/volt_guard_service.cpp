// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SoC Centric LLC
//
// volt_guard_service.cpp - gRPC service implementation
//
/// @brief Implements power mode switching and sensor telemetry
///        with simulated PMIC and voltage rail access.

#include "service/volt_guard_service.hpp"
#include <iostream>

namespace voltguard {

grpc::Status VoltGuardServiceImpl::SetPowerMode(
    grpc::ServerContext*,
    const PowerMode* request,
    ModeResponse* response)
{
    std::cout << "Set mode " << request->mode()
              << " " << request->power_mw() << "mW\n";
    response->set_success(true);
    return grpc::Status::OK;
}

grpc::Status VoltGuardServiceImpl::GetPowerMode(
    grpc::ServerContext*,
    const Empty*,
    PowerMode* response)
{
    response->set_mode(1);
    response->set_power_mw(15000);
    return grpc::Status::OK;
}

grpc::Status VoltGuardServiceImpl::GetSensors(
    grpc::ServerContext*,
    const Empty*,
    SensorData* response)
{
    response->set_temp_celsius(45);
    response->set_voltage_mv(12000);
    response->set_current_ma(800);
    response->set_power_mw(9600);
    return grpc::Status::OK;
}

grpc::Status VoltGuardServiceImpl::HealthCheck(
    grpc::ServerContext*,
    const Empty*,
    HealthResponse* response)
{
    response->set_status("SERVING");
    response->set_version("0.1.0");
    return grpc::Status::OK;
}

} // namespace voltguard
