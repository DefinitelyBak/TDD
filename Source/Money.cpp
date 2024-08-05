#include "Money.h"

#include "Dollar.h"
#include "Franc.h"


namespace Exchanger
{

    Money::Money(double value, std::string currency)
    {
        _ammount = value;
        _currency = currency;
    }

    bool Money::Equals(std::unique_ptr<Money> value) const
    {
        return _ammount == value->_ammount && _currency == value->_currency;
    }

    std::unique_ptr<Money> Money::Dollar(double ammount)
    {
        return std::unique_ptr<Money>(new Exchanger::Dollar(ammount, "USD"));
    }

   std::unique_ptr<Money> Money::Franc(double ammount)
    {
        return std::unique_ptr<Money>(new Exchanger::Franc(ammount, "CHF"));
    }

    std::string Money::Currency() const
    {
        return _currency;
    }

    std::unique_ptr<Money> Money::Times(double multiplier)
    {
        if (_currency == "USD")
            return Money::Dollar(_ammount * multiplier);
        else
            return Money::Franc(_ammount * multiplier);
    }

    std::string Money::ToString() const
    {
        return std::to_string(_ammount) + " " + _currency;
    }

}