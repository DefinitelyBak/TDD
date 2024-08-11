#include "Precompile.h"

#include "Money.h"
#include "Sum.h"
#include "Bank.h"


using namespace Exchanger;

int main()
{
    Bank bank;
    bank.AddRate("USD", "RUB", 0.012);
    bank.AddRate("CHF", "USD", 2);
    auto dollar = Money::Dollar(1);
    auto franc = Money::Franc(10);
    auto res = dollar->Plus(franc)->Times(2);
    auto resCash = bank.Reduce(res, "USD");

    std::cout << "USD: " << resCash->ToString() << std::endl;
    std::cout << "RUB: " << bank.Reduce(resCash, "RUB")->ToString() <<  std::endl << std::endl;


    std::cout << "Hello, TDD!" << std::endl;
}