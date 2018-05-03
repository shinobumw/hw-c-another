#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;

double poly(double x)
{
    return x * x * x + 3 * x;
}

double integrate(double (*f)(double), double a, double b, double dx)
{
    int n = floor((b - a) / dx);
    double integral = 0.0;
    for (int i = 0; i < n; ++i)
        integral += f(a + dx * i) * dx;
    integral += f(a + dx * n) * (b - (a + dx * n));
    return integral;
}

int main()
{
    freopen("data.in", "r", stdin);

    string f;
    double from, to, interval, y = 0.0;
    while (cin >> f >> from >> to >> interval) {
        double a = min(from, to);
        double b = max(from, to);

        if (f == "sin") {
            y = integrate(sin, a, b, interval);
            cout << "The integral of " << f
                 << " from " << from << " to " << to
                 << " = " << ((from > to)? -y : y) << '\n';
            cout << "The real value computed by internal function = " << (- cos(to) + cos(from)) << '\n';
        }
        else if (f == "cos") {
            y = integrate(cos, a, b, interval);
            cout << "The integral of " << f
                 << " from " << from << " to " << to
                 << " = " << ((from > to)? -y : y) << '\n';
            cout << "The real value computed by internal function = " << (sin(to) - sin(from)) << '\n';
        }
        else {
            y = integrate(poly, a, b, interval);
            cout << "The integral of f(x) = " << f
                 << " from " << from << " to " << to
                 << " = " << ((from > to)? -y : y) << '\n';
        }
    }
    return 0;
}
