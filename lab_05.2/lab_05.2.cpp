#include <iostream>
#include <iomanip>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;

double S(double x, double eps, int &n, double s);
double A(double x, int n, double a);

int main()
{
	setlocale(LC_ALL, "ukr");
	double x, xp, xk, dx, eps, s=0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "---------------------------------------\n";
	cout << "|" << setw(28) << "Заголовок таблицi" << setw(10) << "|" << "\n";
	cout << "---------------------------------------\n";
	cout << "|" << setw(3) << "x" << setw(4) << "|" << setw(10) << "arctg(x)" << setw(2) << "|" << setw(5) << "S" << setw(5) << "|" << setw(5) << "n" << setw(5) << "|\n";
	cout << "---------------------------------------\n";
	x = xp;

	while (x <= xk)
	{
		s = S(x, eps, n, s);

		cout << "|" << setw(5) << setprecision(2) << x << " |"
			<< setw(8) << setprecision(5) << atan(x) << "   |"
			<< setw(8) << setprecision(5) << M_PI / 2 + s << " |"
			<< setw(6) << n << "  |"
			<< endl;
		x += dx;
	}
}

double S(double x, double eps, int &n, double s) {
	n = 0;
	double a = -1/x;
	s = a;
	do {
		n++;
		a = A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}

double A(double x, int n, double a) {
	a *= (-(2 * n - 1) / (2 * static_cast<double>(n) + 1)) * (1 / (x * x));
	return a;
}