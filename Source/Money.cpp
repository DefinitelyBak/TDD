#include "Money.h"
#include "Sum.h"
#include "Bank.h"


namespace Exchanger
{

    Money::Money(double value, std::string currency) //: Expression()
    {
        _ammount = value;
        _currency = currency;
    }

    Money::Money(const Money &obj)
    {
        _ammount = obj.Ammount();
        _currency = obj.Currency();
    }

    bool Money::Equals(std::shared_ptr<Money> value) const
    {
        return _ammount == value->Ammount() && _currency == value->Currency();
    }

    std::shared_ptr<Money> Money::Dollar(double ammount)
    {
        return std::make_shared<Money>(ammount, "USD");
    }

   std::shared_ptr<Money> Money::Franc(double ammount)
    {
        return std::make_shared<Money>(ammount, "CHF");
    }

    std::string Money::Currency() const
    {
        return _currency;
    }

    double Money::Ammount() const
    {
        return _ammount;
    }

    std::shared_ptr<Money> Money::Times(double multiplier)
    {
        return std::make_shared<Money>(_ammount * multiplier, _currency);
    }

    std::shared_ptr<Money> Money::Reduce(Bank* bank, std::string to)
    {
        int rate = bank->Rate(_currency, to);
        return std::make_shared<Money>(_ammount/rate, _currency);
    }

    std::string Money::ToString() const
    {
        return std::to_string(_ammount) + " " + _currency;
    }

    std::shared_ptr<Sum> operator+(std::shared_ptr<Money> lhr, std::shared_ptr<Money> rhs)
    {
        return std::make_shared<Sum>(lhr, rhs);
    }

}