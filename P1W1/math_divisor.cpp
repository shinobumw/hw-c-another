#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n);

int main()
{
    int n;
    cin >> n;

    while (n--) {
        int q1, r1, q2, r2;
        cin >> q1 >> r1 >>  q2 >> r2;

        int m = q1 - r1;
        int n = q2 - r2;

        int d = gcd(m, n);

        for (int i = 1; i <= d; ++i)
            if (d % i == 0)
                cout << i << ((i >= d) ? "\n" : " ");
    }

    return 0;
}

int gcd(int m, int n)
{
    int temp;
    while (n != 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}
