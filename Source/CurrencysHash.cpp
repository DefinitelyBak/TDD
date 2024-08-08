#include "CurrencysHash.h"


namespace Exchanger
{

    std::size_t currencysHash::operator()(const Exchanger::currencys & s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first);
        std::size_t h2 = std::hash<std::string>{}(s.second);
        return h1 ^ (h2 << 1);
    }

}