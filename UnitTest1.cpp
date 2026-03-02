#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Admin\Desktop\1\Project7\Project7\Source.cpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(_test_1)
        {
            srand(0);

            double result = monte_carlo(4, 8, 2, 5, 100000);
            Assert::AreEqual(2.0, result, 0.1);
        }


        TEST_METHOD(_test_2)
        {
            srand(0);
            double result = monte_carlo(4, 8, 2, 5, 10);
            Assert::IsTrue(result > 0); 
            Assert::IsTrue(result < 10);
        }


        TEST_METHOD(_test_3)
        {
            srand(42);
            double r1 = monte_carlo(4, 8, 2, 5, 10000);

            srand(42);
            double r2 = monte_carlo(4, 8, 2, 5, 10000);

            Assert::AreEqual(r1, r2);
        }
    };
}