#pragma once

#include <string>


namespace Exchanger
{
    class Money;
    class Bank;

    class Expression
    {
    public:
        virtual ~Expression() = default;

        virtual std::shared_ptr<Money> Reduce(Bank* bank, std::string to) = 0;
    };

}