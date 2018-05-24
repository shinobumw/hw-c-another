#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;
size_t board[MAX][MAX], dp[MAX][MAX];

size_t sol(int n)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + board[i][j];
    return dp[n][n];
}

main()
{
    // freopen("input_dp_jewel", "r", stdin);

    int n;
    while (cin >> n && n) {
        memset(board, 0, sizeof(board));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> board[i][j];
        cout << sol(n) << endl;
    }
}
