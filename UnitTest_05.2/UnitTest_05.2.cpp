#include "pch.h"
#include "CppUnitTest.h"
#include <corecrt_math_defines.h>
#include "../lab_05.2/lab_05.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest052
{
	TEST_CLASS(UnitTest052)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double x = 1.5, xk = 2.0, dx = 0.1, eps = 0.000001, s, a, R;
			int n;

			n = 0;
			a = -1 / x;
			s = a;
			do {		//Test	S()
				n++;
				R = (-(2 * n - 1) / (2.0 * n + 1)) * (1 / (x * x));
				a *= R;
				s += a;
			} while (abs(a) >= eps);
			Assert::AreEqual(s, S(x, eps, n, a));
		}
		TEST_METHOD(TestMethod2)
		{
			double x = 1.5, a=1;
			int n = 2;	//Test  A()

			a *= (-(2 * n - 1) / (2 * static_cast<double>(n) + 1)) * (1 / (x * x));
			Assert::AreEqual(a, A(x,n,1));
		}
	};
}
