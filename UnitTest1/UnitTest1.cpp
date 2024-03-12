#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.2/IntegerSet.h"
#include "../lab2.2/IntegerSet.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arrA[] = { 1, 2, 3 };
			IntegerSet A(arrA, 3);
			int arrB[] = { 3, 4, 5 };
			IntegerSet B(arrB, 3);

			IntegerSet intersectionSet = A * B;
			std::string t = intersectionSet.toString();

			Assert::AreEqual(t.c_str(), "{ 3 }");
		}
	};
}
