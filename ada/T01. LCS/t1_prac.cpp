#include <bits/stdc++.h>
using namespace std;

char x[505], y[505];
int dp[505][505];

int lcs(int lx, int ly)
{
    for (int i = 1; i <= lx; ++i) {
        for (int j = 1; j <= ly; ++j) {
            if (x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[lx][ly];
}

int main()
{
    while (cin >> x >> y) {
        memset(dp, 0, sizeof(dp));
        int lx = strlen(x);    
        int ly = strlen(y);
        cout << lcs(lx, ly) << '\n';    
    }
    return 0;
}
