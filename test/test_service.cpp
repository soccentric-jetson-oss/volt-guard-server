#include <catch2/catch_test_macros.hpp>
#include <volt_guard.grpc.pb.h>

TEST_CASE("PowerMode validation", "[server]") {
    voltguard::PowerMode pm;
    pm.set_mode(1);
    pm.set_power_mw(15000);
    REQUIRE(pm.mode() == 1);
    REQUIRE(pm.power_mw() == 15000);
}

TEST_CASE("SensorData validation", "[server]") {
    voltguard::SensorData sd;
    sd.set_temp_celsius(45);
    sd.set_voltage_mv(12000);
    sd.set_current_ma(800);
    sd.set_power_mw(9600);
    REQUIRE(sd.temp_celsius() == 45);
    REQUIRE(sd.voltage_mv() == 12000);
    REQUIRE(sd.current_ma() == 800);
    REQUIRE(sd.power_mw() == 9600);
}
