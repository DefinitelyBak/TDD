#pragma once

#include "Money.h"


namespace Exchanger
{

    class Franc: public Money
    {
    public:
        Franc(double value, std::string currency);
        ~Franc() override = default;
    };

}