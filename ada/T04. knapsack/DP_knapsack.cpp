#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 501;
const int MAX_W = 100001;

int w[MAX_W], v[MAX_N];
int dp[MAX_N][MAX_W];

int kp(int n, int weight)
{
    // for (int i = 0; i <= n; ++i)
    //     dp[i][0] = 0;
    // for (int i = 0; i <= weight; ++i)
    //     dp[0][i] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= weight; ++j) {    // Total weight
            if (w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
        }
    }
    return dp[n][weight];
}

int main()
{
    // freopen("input", "r", stdin);

    int n;
    while (cin >> n && n) {
        int weight;
        cin >> weight;
        for (int i = 1; i <= n; ++i)
            cin >> w[i] >> v[i];

        memset(dp, 0, sizeof(dp));
        cout <<  kp(n, weight) << "\n";
    }
    return 0;
}
