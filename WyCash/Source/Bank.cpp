#include "Bank.h"


namespace Exchanger
{

    std::shared_ptr<Money> Bank::Reduce(std::shared_ptr<Expression> source, std::string to)
    {
        return source->Reduce(this, to);
    }

    void Bank::AddRate(std::string from, std::string to, double rate)
    {
        _hashtable.emplace(currencys(from, to), rate);
    }

    double Bank::Rate(std::string from, std::string to)
    {
        if (from == to ) return 1;
        
        try
        {
            return _hashtable.at(currencys(from, to));
        }
        catch(const std::exception& e)
        {
            throw;
        }
                
    }
}