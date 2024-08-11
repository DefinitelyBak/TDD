#include "TestCaseTest.h"


namespace xUnit
{

    void TestCaseTest::SetUp()
    {
        _resultTest = xUnit::TestResult();
        _test = WasRun<void()>(xUnit::TestFirst, TestCase::GetNameFunction());
    }

}