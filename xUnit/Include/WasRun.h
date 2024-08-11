#pragma once

#include "Precompile.h"

#include "TestCase.h"


namespace xUnit
{

    /// @brief 
    /// @tparam T 
    template<class T>
    class WasRun: public TestCase<T>
    {
    public:
        using fuctionType = std::function<T>;

        WasRun() = default;

        WasRun(fuctionType funct, std::string nameFunction): TestCase<T>(funct, nameFunction)
        {}

        std::string GetLog()
        {
            return _log;
        }

    private:

        void SetUp() override
        {
            _log = "setUp ";
        }

        void TearDown() override
        {
            _log += TestCase<T>::GetNameFunction() + " tearDown";
        }

        std::string _log;

    };

}