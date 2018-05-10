#include <bits/stdc++.h>
using namespace std;

int p[55];
int dp[55][55];

int cost(int i, int j)
{
     if (dp[i][j] > -1)
        return dp[i][j];
    if (i + 1 == j)
        return dp[i][j] = 0;
   
    int ans = INT_MAX;
    for (int k = i + 1; k < j; ++k) {
        ans = min(ans, cost(i, k) + cost(k, j));
    }
   
    return dp[i][j] = ans + p[j] - p[i];
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

        cout << "The minimum cutting is " << cost(0, n+1) << ".\n";    
    }
    return 0;
}
