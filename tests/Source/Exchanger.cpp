#include <catch2/catch_test_macros.hpp>

#include "Money.h"
#include "Sum.h"
#include "Bank.h"


using namespace Exchanger;

TEST_CASE("Multiplication", "[Dollar][Money]")
{
    auto five = Money::Dollar(5);
    REQUIRE(Money::Dollar(10)->Equals(five->Times(2)));
    REQUIRE(Money::Dollar(15)->Equals(five->Times(3)));
}

TEST_CASE("Equality", "[Dollar][Franc][Money]")
{
    REQUIRE(Money::Dollar(5)->Equals(Money::Dollar(5)));
    REQUIRE_FALSE(Money::Dollar(5)->Equals(Money::Dollar(6)));
    REQUIRE_FALSE(Money::Franc(5)->Equals(Money::Dollar(5)));
}

TEST_CASE("Currency", "[Dollar][Franc][Money]")
{
    REQUIRE((Money::Dollar(1)->Currency() == "USD"));
    REQUIRE((Money::Franc(1)->Currency() == "CHF"));
}

TEST_CASE("Simple addition", "[Dollar]")
{
    auto five = Money::Dollar(5);
    auto sum = five + five;
    auto bank = std::make_unique<Bank>();
    auto reduced = bank->Reduce(sum, "USD");
    REQUIRE(reduced->Equals(Money::Dollar(10)));
}

TEST_CASE("Plus returns sum", "[Dollar]") 
{
    auto five = Money::Dollar(5);
    auto sum = five + five;
    REQUIRE((five.get() == sum->augend.get()));
    REQUIRE((five.get() == sum->addend.get()));
}

TEST_CASE("Reduce money")
{
    Bank bank;
    auto result = bank.Reduce(Money::Dollar(1), "USD");
    REQUIRE(Money::Dollar(1)->Equals(result));
}

TEST_CASE("Reduce money different currency") 
{
    Bank bank;
    bank.AddRate("CHF", "USD", 2);
    auto result = bank.Reduce(Money::Franc(2), "USD");
    REQUIRE(Money::dollar(1)->Equality(result));
}