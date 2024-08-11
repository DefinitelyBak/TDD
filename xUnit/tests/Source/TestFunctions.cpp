#include "TestFunctions.h"


namespace xUnit
{

    void TestFirst()
    {};

    void TestBrokenMethod()
    {
        throw std::domain_error("Error in TestBrokenMethod");
    };

}
