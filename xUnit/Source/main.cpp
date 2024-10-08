#include "Precompile.h"

#include "TestSuite.h"


using namespace xUnit;

int FunctionDone()
{
    return 55;
};

int FunctionError()
{
    throw(std::exception());
    return -1;
};


int main()
{
    TestSuite<int()> testSuite;
    testSuite.Add(WasRun<int()>(FunctionDone, "FunctionDone"));
    testSuite.Add(WasRun<int()>(FunctionError, "FunctionError"));

    TestResult result;
    testSuite.Run(result);

    std::cout << result.Summary() << std::endl;
}