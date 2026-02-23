#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestFindElement)
        {
            auto list = spis_(5);
            Assert::IsTrue(find_in_spis(list, 1));
        }
        TEST_METHOD(TestFindNonElement)
        {
            auto list = spis_(5);
            Assert::IsFalse(find_in_spis(list, 999));
        }
        TEST_METHOD(TesList)
        {
            auto list = spis_(0);
            Assert::IsFalse(find_in_spis(list, 1));
        }
    };
}