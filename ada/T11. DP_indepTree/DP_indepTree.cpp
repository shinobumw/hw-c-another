#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int dp0[MAX], dp1[MAX];
int w[MAX];

void sol()
{
    int n;
    cin >> n >> w[1];

    int parent[MAX], degree[MAX];
    memset(degree, 0, sizeof(degree));
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i] >> w[i];
        degree[parent[i]]++;
    }

    for (int i = 1; i <= n; ++i) {
        dp0[i] = 0;
        dp1[i] = w[i];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int p = parent[v];
        dp0[p] += max(dp0[v], dp1[v]);
        dp1[p] += dp0[v];
        degree[p]--;
        if (degree[p] == 0)
            q.push(p);
    }

    cout << max(dp0[1], dp1[1]) << '\n';
}

int main()
{
    // freopen("input", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        sol();
    }
    return 0;
}
