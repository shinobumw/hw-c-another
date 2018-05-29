#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 20;

int c[MAX], w[MAX];

int dp(int m, int n)
{
    // Lazy DP
    if (c[m] >= 0)
        return c[m];
    
    int mm = 0;
    for (int i = 0; i < n; ++i) {
        if (m & (1 << i)) {
            int k = dp(m ^ (1 << i), n);
            if (k > mm)
                mm = k;
        }
    }
    c[m] = mm + w[m];
    return c[m];
}

main()
{
    int n;
    while (cin >> n && n) {
        int m = 1 << n;    // 2^n
        for (int i = 0; i < m; ++i) {
            cin >> w[i];
            c[i] = -1;
        }
        c[0] = w[0];
        cout << dp(m - 1, n) << endl;
    }
}
