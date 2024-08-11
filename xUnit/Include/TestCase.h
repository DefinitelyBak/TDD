#pragma once

#include "Precompile.h"

#include "TestResult.h"


namespace xUnit
{
    template<class T>
    class TestCase
    {
    public:
        using fuctionType = std::function<T>;

        TestCase() = default;
        TestCase(fuctionType funct, std::string nameFunction):
            _funct(funct), _nameFunction(nameFunction)
        {}

        void Run(TestResult& result)
        {
            result.TestStarted();
            SetUp();
            try
            {
                _funct();
            }
            catch(const std::exception& e)
            {
                result.TestFailed(e);
            }
            catch(...)
            {
                result.TestFailed(std::exception());
            }

            TearDown();
        }

    protected:
        std::string GetNameFunction()
        {
            return _nameFunction;
        }

    private:

        virtual void SetUp() = 0;
        virtual void TearDown() = 0;

        fuctionType _funct;
        std::string _nameFunction;
    };

}