#include "stdafx.h"
#include "CppUnitTest.h"
#include "D:\Alex\Documents\C++\Visual Studio 2013\Projects\1.University\lab2_unit\lab2_unit\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(calc_tests)
	{
	public:
		
		TEST_METHOD(calc_get5and7_8returned)	//right
		{
			int x = 5;
			int n = 7;
			int expected = 8;
			int actual = calc(x, n);
			Assert::AreEqual(expected, actual);
		}

	public:

		TEST_METHOD(calc_get6and9_12returned)	//not right
		{
			int x = 6;
			int n = 9;
			int expected = 12;
			int actual = calc(x, n);
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(checkValidParams_Tests)
	{
	public:
		TEST_METHOD(checkValidParams_get10_eceptionNotThrown)	//right
		{
			int x = 2;
			int n = 10;
			int xMax = 5;
			int step = 2;
			try
			{
				checkParam(x, n, xMax, step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkValidParams_get3_eceptionNotThrown)	//not right
		{
			int x = 5;
			int n = 1;
			int xMax = 2;
			int step = 3;
			try
			{
				checkParam(x, n, xMax, step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	};
}
