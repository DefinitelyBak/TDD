#pragma once

#include <memory>
#include <unordered_map>

#include "Money.h"


namespace Exchanger
{

    class Bank
    {
    public:
        std::shared_ptr<Money> Reduce(std::shared_ptr<Expression> source, std::string to);

        void AddRate(std::string from, std::string to, double rate);
        double Rate(std::string from, std::string to);

    private:
        using currencys = std::pair<std::string, std::string>;
        std::unordered_map<currencys, double> _hashtable;

    };

}