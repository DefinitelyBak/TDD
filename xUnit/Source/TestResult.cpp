#include "TestResult.h"


namespace xUnit
{
    TestResult::TestResult(): _runCount(0), _errorCount(0)
    {}

    std::string TestResult::Summary()
    {
        return std::to_string(_runCount) + " run, " + std::to_string(_errorCount)+ " failed" + _errorLog;
    }

    void TestResult::TestStarted()
    {
        _runCount += 1;
    }

    void TestResult::TestFailed(const std::exception& e)
    {
        _errorCount += 1;
        _errorLog = " error: " + std::string(e.what());
    }

}