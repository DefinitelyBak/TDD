#include <catch2/catch_test_macros.hpp>

#include "Money.h"
#include "Sum.h"
#include "Bank.h"


using namespace Exchanger;

TEST_CASE("Copy constructor", "[Money]")
{
    std::shared_ptr<Money> value = Money::Dollar(5);
    std::shared_ptr<Money> newValue = std::make_shared<Money>(*value);
    REQUIRE(newValue == value);
    REQUIRE_FALSE(newValue.get() == value.get());
}

TEST_CASE("Multiplication", "[Money]")
{
    auto five = Money::Dollar(5);
    REQUIRE(Money::Dollar(10) == five->Times(2));
    REQUIRE(Money::Dollar(15) == five->Times(3));
}

TEST_CASE("Equality", "[Money]")
{
    REQUIRE(Money::Dollar(5) == Money::Dollar(5));
    REQUIRE_FALSE(Money::Dollar(5) == Money::Dollar(6));
    REQUIRE_FALSE(Money::Franc(5) == Money::Dollar(5));
}

TEST_CASE("Currency", "[Money]")
{
    REQUIRE(Money::Dollar(1)->GetCurrency() == "USD");
    REQUIRE(Money::Franc(1)->GetCurrency() == "CHF");
}

TEST_CASE("Simple addition", "[Money]")
{
    auto five = Money::Dollar(5);
    auto sum = five->Plus(five);
    auto bank = std::make_unique<Bank>();
    auto reduced = bank->Reduce(sum, "USD");
    REQUIRE(reduced == Money::Dollar(10));
}

TEST_CASE("Reduce money", "[Money]")
{
    Bank bank;
    auto result = bank.Reduce(Money::Dollar(1), "USD");
    REQUIRE(Money::Dollar(1) == result);
}

TEST_CASE("Identity rate", "[Money]")
{
    REQUIRE(1.0 == Bank().Rate("USD", "USD"));
}

TEST_CASE("Reduce money different currency", "[Money]") 
{
    Bank bank;
    bank.AddRate("CHF", "USD", 2);
    auto result = bank.Reduce(Money::Franc(2), "USD");
    REQUIRE((Money::Dollar(1) == result));
}

TEST_CASE("Mixed addition", "[Money]")
{
    std::shared_ptr<Expression> fiveBucks = Money::Dollar(5);
    std::shared_ptr<Expression> tenFnacs = Money::Franc(10);
    Bank bank;
    bank.AddRate("CHF", "USD", 2);
    std::shared_ptr<Expression> result = bank.Reduce(fiveBucks->Plus(tenFnacs), "USD");
    REQUIRE(result == Money::Dollar(10));
}

TEST_CASE("Sum plus money", "[Money]")
{
    std::shared_ptr<Expression> fiveBucks = Money::Dollar(5);
    std::shared_ptr<Expression> tenFrancs = Money::Franc(10);
    Bank bank;
    bank.AddRate("CHF", "USD", 2);
    std::shared_ptr<Expression> sum =  std::make_shared<Sum>(fiveBucks, tenFrancs)->Plus(fiveBucks);
    std::shared_ptr<Expression> result = bank.Reduce(sum, "USD");
    REQUIRE(result == Money::Dollar(15));
}

TEST_CASE("Sum times", "[Money]")
{
    std::shared_ptr<Expression> fiveBucks = Money::Dollar(5);
    std::shared_ptr<Expression> tenFrancs = Money::Franc(10);
    Bank bank;
    bank.AddRate("CHF", "USD", 2);
    std::shared_ptr<Expression> sum =  std::make_shared<Sum>(fiveBucks, tenFrancs)->Times(2);
    std::shared_ptr<Expression> result = bank.Reduce(sum, "USD");
    REQUIRE(result == Money::Dollar(20));
}

TEST_CASE("Plus same currency returns money", "[Money]")
{
    std::shared_ptr<Expression> sum = Money::Dollar(1)->Plus(Money::Dollar(1));
    std::string infoName(typeid(*sum).name());
    std::transform(infoName.begin(), infoName.end(), infoName.begin(),
        [](unsigned char c){ return std::tolower(c); });
    REQUIRE(infoName.find("money") != std::string::npos);
}