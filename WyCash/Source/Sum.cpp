#include "Sum.h"


namespace Exchanger
{

    Sum::Sum(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs): _augend(lhs), _addend(rhs)
    {}

    std::shared_ptr<Money> Sum::Reduce(Bank* bank, std::string to) const
    {
        double amount = _augend->Reduce(bank, to)->GetAmmount() + _addend->Reduce(bank, to)->GetAmmount();
        return std::make_shared<Money>(amount, to);
    }

    std::shared_ptr<Expression> Sum::Times(double multiplier) const
    {
        return std::make_shared<Sum>(_augend->Times(multiplier), _addend->Times(multiplier));
    }

    std::shared_ptr<Expression> Sum::Plus(std::shared_ptr<Expression> addend) const
    {
        return std::make_shared<Sum>(std::make_shared<Sum>(_augend, _addend), addend);
    }

}