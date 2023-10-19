#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double S(const double x, const double eps, int& n);
double A(const double x, const int n);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    const double PI = 3.141592653589793238;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "acos(x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n); 
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << acos(x) << " |"
            << setw(10) << setprecision(5) << s << " |" 
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n)
{
    n = 1;
    double a = x * x * x / 6;
    double s = a; 
    do {
        n++;
        a = A(x, n);
        s += a; 
    } while (abs(a) >= eps);
    return s;
}
double A(const double x, const int n)
{
    double R = (x * (2 * n - 1) * (2 * n - 1)) / ((2 * n + 1) * (2 * n - 2));
    double a = x * x * x * R; 
    return a;
}
