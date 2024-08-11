#pragma once

#include "Precompile.h"

#include "TestSuite.h"
#include "TestCase.h"
#include "WasRun.h"
#include "TestFunctions.h"

namespace xUnit
{

    class TestCaseTest: public TestCase<void()>
    {
    public:
        using fuctionType = std::function<void( TestCaseTest* obj)>;

        TestCaseTest(fuctionType func, std::string nameFunction): TestCase<void()>(std::bind(func, this), nameFunction)
        {};

        void TestTemplateMethod()
        {
            _test.Run(_resultTest);
            assert("setUp TestTemplateMethod tearDown" == _test.GetLog());
        }

        void TestResult()
        {
            _test.Run(_resultTest);
            assert("1 run, 0 failed" == _resultTest.Summary());
        }

        void TestFailedResult()
        {
            xUnit::TestResult resultTest;
            _test = WasRun<void()>(xUnit::TestBrokenMethod, TestCase::GetNameFunction());
            _test.Run(resultTest);
            assert("1 run, 1 failed error: Error in TestBrokenMethod" == resultTest.Summary());
        }

        void FailedResultFormatting()
        {
            auto result = xUnit::TestResult();
            result.TestStarted();
            result.TestFailed();
            assert("1 run, 1 failed error: std::exception" == result.Summary());
        }

        void TestSuite()
        {
            auto suite = xUnit::TestSuite<void()>();
            suite.Add(WasRun<void()>(xUnit::TestFirst, "testMethod"));
            suite.Add(WasRun<void()>(xUnit::TestBrokenMethod, "TestBrokenMethod"));
            suite.Run(_resultTest);
            assert("2 run, 1 failed error: Error in TestBrokenMethod" == _resultTest.Summary());
        }

    private:
        void SetUp() override;

        void TearDown() override
        {}

        WasRun<void()> _test;
        xUnit::TestResult _resultTest;
    };

}