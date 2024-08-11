#pragma once

#include "Precompile.h"


namespace xUnit
{

    class TestResult
    {
    public:
        TestResult();
        std::string Summary();

        void TestStarted();

        void TestFailed(const std::exception& e = std::exception());

    private:
        int _runCount;
        int _errorCount;
        std::string _errorLog;
    };

}