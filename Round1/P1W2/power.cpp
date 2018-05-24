#include <bits/stdc++.h>
using namespace std;

long long qp(long long a, long long b, int p)
{
    if (a == 0) return 0;
    long long ans = 1;
    while (b) {
        if (b & 1) ans = (ans % p) * (a % p);
        b >>= 1;
        a = (a % p) * (a % p);
    }
    return ans % p;
}

int main()
{
    char x[204], n[204]; 
    int p;
    while (scanf("%s%s%d", x, n, &p) == 3) {
        long long a = 0, b = 0;
        for (int i = 0; x[i]; ++i) 
            a = (a * 10 + x[i] - '0') % p;
        for (int i = 0; n[i]; ++i) 
            b = (b * 10 + n[i] - '0') % (p - 1);    // Fermat’s Little Theorem
        cout << qp(a, b, p) << endl;
    }
    return 0;
}