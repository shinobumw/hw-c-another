/**
 * if j = i + 1 then dp[i][j] = 0
 * dp[i][j] = min(dp[i][k] + dp[k][j] | for i < j < k) + (p[j] - p[i])
 */


#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int dp[55][55], p[55];

int cost(int x, int y)
{
    if (dp[x][y] > -1)
        return dp[x][y];
    if (x + 1 == y)
        return dp[x][y] = 0;

    int ans = INF;
    for (int i = x + 1; i < y; ++i) {
        ans = min(ans, cost(x, i) + cost(i, y));
    }
    return dp[x][y] = ans + p[y] - p[x];
}

int main()
{
    int l;
    while (cin >> l && l) {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> p[i];
        p[0] = 0;
        p[n+1] = l;
        cout << "The minimum cutting is " <<  cost(0, n + 1) << ".\n";
    }
    return 0;
}
