#include "Money.h"
#include "Sum.h"
#include "Bank.h"


namespace Exchanger
{

    Money::Money(double value, std::string currency): Expression(), _ammount(value), _currency(currency)
    {}

    std::shared_ptr<Money> Money::Dollar(double ammount)
    {
        return std::make_shared<Money>(ammount, "USD");
    }

   std::shared_ptr<Money> Money::Franc(double ammount)
    {
        return std::make_shared<Money>(ammount, "CHF");
    }

    std::shared_ptr<Expression> Money::Plus(std::shared_ptr<Expression> addend) const
    {
        return std::make_shared<Sum>(std::make_shared<Money>(*this), addend);
    }

    std::shared_ptr<Expression> Money::Plus(std::shared_ptr<Money> addend) const
    {
        if (_currency == addend->GetCurrency())
            return std::make_shared<Money>(_ammount + addend->GetAmmount(), _currency);
        
        return std::make_shared<Sum>(std::make_shared<Money>(*this), addend);
    }

    std::shared_ptr<Expression> Money::Times(double multiplier) const
    {
        return std::make_shared<Money>(_ammount * multiplier, _currency);
    }

    std::shared_ptr<Money> Money::Reduce(Bank* bank, std::string to) const
    {
        double rate = bank->Rate(_currency, to);
        return std::make_shared<Money>(_ammount/rate, to);
    }

    std::string Money::ToString() const
    {
        return std::to_string(_ammount) + " " + _currency;
    }

    bool operator==(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs)
    {
        try
        {
            Money* mlhs = dynamic_cast<Money*>(lhs.get());
            Money* mrhs = dynamic_cast<Money*>(rhs.get());

            if (mlhs == nullptr || mrhs == nullptr)
                return false;

            if (mlhs->GetAmmount() == mrhs->GetAmmount() && 
                mlhs->GetCurrency() == mrhs->GetCurrency())
                return true;
        }
        catch(const std::exception& e)
        {}

        return false;
    }

    bool operator==(std::shared_ptr<Money> lhs, std::shared_ptr<Money> rhs)
    {
        return Exchanger::operator==(std::shared_ptr<Expression>(lhs), std::shared_ptr<Expression>(rhs));
    }
    
    bool operator==(std::shared_ptr<Expression> lhs, std::shared_ptr<Money> rhs)
    {
        return Exchanger::operator==(lhs, std::shared_ptr<Expression>(rhs));
    }

    bool operator==(std::shared_ptr<Money> lhs, std::shared_ptr<Expression> rhs)
    {
        return Exchanger::operator==(std::shared_ptr<Expression>(lhs), rhs);
    }

}