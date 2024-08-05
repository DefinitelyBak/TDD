#include "Sum.h"


namespace Exchanger
{

    Sum::Sum(std::shared_ptr<Money> lhs, std::shared_ptr<Money> rhs)
    {
        augend = lhs;
        addend = rhs;
    }

    std::shared_ptr<Money> Sum::Reduce(Bank* bank, std::string to)
    {
        return std::make_shared<Money>(augend->Ammount() + addend->Ammount(), to);
    }
}