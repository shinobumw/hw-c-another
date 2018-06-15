#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

void sol()
{
    int n, w[MAX], parent[MAX], degree[MAX] = {0};
    cin >> n >> w[1];
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i] >> w[i];
        degree[parent[i]]++;
    }

    int dp0[MAX], dp1[MAX];
    for (int i = 1; i <= n; ++i) {
        dp0[i] = 0;
        dp1[i] = w[i];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        int p = parent[c];
        dp0[p] += max(dp0[c], dp1[c]);
        dp1[p] += dp0[c];
        degree[p]--;
        if (degree[p] == 0)
            q.push(p);
    }
    cout << max(dp0[1], dp1[1]) << endl;
}

main()
{
    // freopen("input", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}
