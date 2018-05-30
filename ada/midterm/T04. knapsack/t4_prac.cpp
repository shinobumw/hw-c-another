#include <bits/stdc++.h>
using namespace std;

int w[505], v[505];
int dp[505][100001];

int kp(int n, int weight)
{
    for (int i = 1;i <= n; ++i) {
        for (int j = 1; j <= weight; ++j) {
            if (w[i] <= j)
                dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][weight];
}

int main()
{
    int n;
    while (cin >> n && n) {
        memset(dp, 0, sizeof(dp));
        int weight;
        cin >> weight;
        for (int i = 1; i <= n; ++i)
            cin >> w[i] >> v[i];
        cout << kp(n, weight) << '\n';
    }
    return 0;
}
