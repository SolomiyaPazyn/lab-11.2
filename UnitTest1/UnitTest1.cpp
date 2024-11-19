#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 11.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тест для одного простого виразу в дужках
			std::string input = "This is a (test) string";
			std::string expected = "This is a  string";
			Assert::AreEqual(expected, ProcessBrackets(input));
		}
	};
}
