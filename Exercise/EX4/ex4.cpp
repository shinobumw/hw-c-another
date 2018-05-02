#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

double poly (double x)
{
    return x * x * x + 3 * x;
}

double integrate(double (*f)(double x), double a, double b)
{
    double t = 0.0001;
    double result = 0.0;
    for (int i = a; i <= b; i += t)
        result += f(i);
    return result * t;
}

int main()
{
    freopen("data.in", "r", stdin);
    // char f[100];
    string f;
    double from, to, interval, y = 0.0;
    while (cin >> f >> from >> to >> interval) {
    // while ((scanf("%s %lld %lld %lld", f, &from, &to, &interval)) == 4) {

        if (f == "sin") {
            y = integrate(sin, from, to);
            cout << f << " from " << from << " to " << to
                 << " = " << y << '\n';
        }
        else if (f == "cos") {
            y = integrate(cos, from, to);
            cout << f << " from " << from << " to " << to
                 << " = " << y << '\n';
        }
        else {
            y = integrate(poly, from, to);
            cout << "integrate f(x) = " << f << " from " << from << " to " << to
                 << " = " << y << '\n';
        }
    }

    return 0;
}
