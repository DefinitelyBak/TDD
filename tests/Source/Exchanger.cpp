#include <catch2/catch_test_macros.hpp>

#include "Money.h"


using namespace Exchanger;

TEST_CASE("DollarMultiplication", "[Dollar]")
{
    auto five = Money::Dollar(5);
    REQUIRE(Money::Dollar(10)->Equals(five->Times(2)));
    REQUIRE(Money::Dollar(15)->Equals(five->Times(3)));
}

TEST_CASE("FrancMultiplication", "[Franc]")
{
    auto five = Money::Franc(5);
    REQUIRE(Money::Franc(10)->Equals(five->Times(2)));
    REQUIRE(Money::Franc(15)->Equals(five->Times(3)));
}

TEST_CASE("Equality", "[Dollar][Franc]")
{
    REQUIRE(Money::Dollar(5)->Equals(Money::Dollar(5)));
    REQUIRE_FALSE(Money::Dollar(5)->Equals(Money::Dollar(6)));
    REQUIRE(Money::Franc(5)->Equals(Money::Franc(5)));
    REQUIRE_FALSE(Money::Franc(5)->Equals(Money::Franc(6)));

    REQUIRE_FALSE(Money::Franc(5)->Equals(Money::Dollar(5)));
}

TEST_CASE("Currency", "[Dollar][Franc]")
{
    REQUIRE((Money::Dollar(1)->Currency() == "USD"));
    REQUIRE((Money::Franc(1)->Currency() == "CHF"));
}