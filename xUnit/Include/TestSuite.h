#pragma once

#include "Precompile.h"

#include "WasRun.h"


namespace xUnit
{

    template<class T>
    class TestSuite
    {
    public:
        TestSuite() = default;

        void Add(WasRun<T>&& test)
        {
            _tests.emplace_back(std::forward<WasRun<T>>(test));
        }

        void Run(TestResult& result)
        {
            for (auto& x: _tests)
                x.Run(result);
        }

    private:
        std::list<WasRun<T>> _tests;
    };

}