//#include <catch2/catch_test_macros.hpp>

#include "Precompile.h"

#include "TestCaseTest.h"


using namespace xUnit;

int main()
{
    TestResult rseult;
    TestCaseTest(TestCaseTest::TestResult, "TestResult").Run(rseult);
    std::cout << rseult.Summary() << std::endl;

    rseult = TestResult();
    TestCaseTest(TestCaseTest::TestTemplateMethod, "TestTemplateMethod").Run(rseult);
    std::cout << rseult.Summary() << std::endl;

    rseult = TestResult();
    TestCaseTest(TestCaseTest::TestFailedResult, "TestFailedResult").Run(rseult);
    std::cout << rseult.Summary() << std::endl;

    rseult = TestResult();
    TestCaseTest(TestCaseTest::FailedResultFormatting, "FailedResultFormatting").Run(rseult);
    std::cout << rseult.Summary() << std::endl;

    rseult = TestResult();
    TestCaseTest(TestCaseTest::TestSuite, "TestSuite").Run(rseult);
    std::cout << rseult.Summary() << std::endl;
}