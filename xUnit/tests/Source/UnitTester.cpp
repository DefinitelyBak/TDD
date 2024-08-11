#include "Precompile.h"

#include "TestCaseTest.h"


using namespace xUnit;

int main()
{
    TestResult result;
    TestCaseTest(TestCaseTest::TestResult, "TestResult").Run(result);
    std::cout << result.Summary() << std::endl;

    result = TestResult();
    TestCaseTest(TestCaseTest::TestTemplateMethod, "TestTemplateMethod").Run(result);
    std::cout << result.Summary() << std::endl;

    result = TestResult();
    TestCaseTest(TestCaseTest::TestFailedResult, "TestFailedResult").Run(result);
    std::cout << result.Summary() << std::endl;

    result = TestResult();
    TestCaseTest(TestCaseTest::FailedResultFormatting, "FailedResultFormatting").Run(result);
    std::cout << result.Summary() << std::endl;

    result = TestResult();
    TestCaseTest(TestCaseTest::TestSuite, "TestSuite").Run(result);
    std::cout << result.Summary() << std::endl;
}