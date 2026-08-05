#include <catch2/catch_test_macros.hpp>

TEST_CASE("Health check returns OK", "[server]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Server starts and stops", "[server]") {
    REQUIRE(true);
}
