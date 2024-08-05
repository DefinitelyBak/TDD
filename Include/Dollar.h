#pragma once

#include "Money.h"


namespace Exchanger
{

    class Dollar: public Money
    {
    public:
        Dollar(double value, std::string currency);
        ~Dollar() override = default;
    };

}