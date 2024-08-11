#include "TestCaseTest.h"


namespace xUnit
{
    TestCaseTest::TestCaseTest(fuctionType func, std::string nameFunction): TestCase<void()>(std::bind(func, this), nameFunction)
    {}

    void TestCaseTest::SetUp()
    {
        _resultTest = xUnit::TestResult();
        _test = WasRun<void()>(xUnit::TestFirst, TestCase::GetNameFunction());
    }

}