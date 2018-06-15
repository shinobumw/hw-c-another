#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

void sol()
{
    int n;
    cin >> n;
    vector<int> e[MAX];
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }

    bool vis[MAX] = {false};
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int v;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto &it: e[v]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
    }

    int d[MAX] = {0};
    int sol = 0;
    fill(vis, vis + n, false);
    q.push(v);
    vis[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto &u: e[v]) {
            if (!vis[u]) {
                d[u] = d[v] + 1;
                sol = max(sol, d[u]);
                q.push(u);
                vis[u] = true;
            }
        }
    }
    cout << sol << endl;
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
