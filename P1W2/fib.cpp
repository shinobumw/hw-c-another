#include <bits/stdc++.h>
using namespace std;

typedef struct MATRIX {
    long long m[3][3];
};

int n, p;
MATRIX mul(MATRIX a, MATRIX b)
{
    MATRIX t = {{{0}}};
    long long s;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            s = 0;
            for (int k = 0; k < 3; ++k)
                s = (s + (a.m[i][k] * b.m[k][j]) % p) % p;
            t.m[i][j] = s;
        }
    return t;
}

long long fib(int n, int p, MATRIX M)
{
    int y = n - 3;
    MATRIX t = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}, xi, t2;
    xi = M;

    while (y) {
        if (y & 1) t = mul(t, xi);
        y >>= 1;
        xi = mul(xi, xi);
    }
    return (t.m[0][0] + t.m[0][1] + t.m[0][2]) % p;
}

int main()
{
    MATRIX M = {{{0, 0, 0}, {1, 0, 0}, {0, 1, 0}}};

    while (scanf("%d%d%lld%lld%lld", &n, &p, &(M.m[0][0]), &(M.m[0][1]), &(M.m[0][2])) == 5) {
        if (n <= 3)
            cout << "1\n";
        else
            cout << fib(n, p, M) << "\n";
    }
    return 0;
}
