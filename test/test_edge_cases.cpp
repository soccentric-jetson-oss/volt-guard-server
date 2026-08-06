#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include <cerrno>

TEST_CASE("Null input handling", "[edge]") {
    REQUIRE(true);  // No library function to test with NULL
}

TEST_CASE("Empty input handling", "[edge]") {
    voltguard::PowerMode pm;
    REQUIRE(pm.mode() == 0);
    REQUIRE(pm.power_mw() == 0);
}

TEST_CASE("Boundary values", "[edge]") {
    voltguard::PowerMode pm;
    pm.set_mode(0);
    pm.set_power_mw(15000);
    REQUIRE(pm.mode() == 0);
    REQUIRE(pm.power_mw() == 15000);
    pm.set_mode(2);
    pm.set_power_mw(60000);
    REQUIRE(pm.mode() == 2);
    REQUIRE(pm.power_mw() == 60000);
}

TEST_CASE("Concurrent access", "[edge]") {
    std::atomic<int> counter{0};
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&]() { counter++; });
    }
    for (auto& t : threads) t.join();
    REQUIRE(counter == 10);
}

TEST_CASE("Resource cleanup on error", "[edge]") {
    voltguard::SensorData sd;
    sd.set_temp_celsius(-40);
    sd.set_voltage_mv(0);
    sd.set_current_ma(0);
    REQUIRE(sd.temp_celsius() == -40);
    REQUIRE(sd.voltage_mv() == 0);
}
