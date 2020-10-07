#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <MyClass.hpp>

TEST_CASE("Application unit tests")
{
    REQUIRE(MyClass().Test());
}
