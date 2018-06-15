#include <bits/stdc++.h>
using namespace std;

const int MAX = 5005;
const int INF = 1e9;

vector<pair<int, int>> e[MAX];
int n, m, q, d[MAX];

bool bfs(int s, int t)
{
    bool vis[MAX] = {false};
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &it: e[u]) {
            int v = it.first;
            if (v == t)
                return true;
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return false;
}

bool sol(int s, int t)
{
    for (int i = 0; i < n; ++i)
        d[i] = INF;
    d[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u)
            for (auto &it: e[u]) {
                int v = it.first;
                int w = it.second;
                if (d[u] < INF && d[v] > d[u] + w)
                    d[v] = d[u] + w;
            }
    }

    for (int u = 0; u < n; ++u) {
        for (auto &it: e[u]) {
            int v = it.first;
            int w = it.second;
            if (d[u] < INF && d[v] > d[u] + w) {
                if (!bfs(u, t))
                    return true;
                else
                    return false;
            }
        }
    }
    return true;
}

main()
{
    // freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> q;

        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back({v, w});
        }

        while (q--) {
            int s, t;
            cin >> s >> t;
            if (s == t) {
                cout << "0\n";
                continue;
            }
            if (sol(s, t)) {
                if (d[t] < INF)
                    cout << d[t] << endl;
                else
                    cout << "no\n";
            }
            else
                cout << "no\n";
        }
    }
}
