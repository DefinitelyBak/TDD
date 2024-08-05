#pragma once

#include "Money.h"


namespace Exchanger
{
    class Bank;

    class Sum: public Expression
    {
    public:
        Sum() = delete;
        Sum(std::shared_ptr<Money> lhs, std::shared_ptr<Money> rhs);

        std::shared_ptr<Money> Reduce(Bank* bank, std::string to) override;

        std::shared_ptr<Money> augend;
        std::shared_ptr<Money> addend;
    };

}