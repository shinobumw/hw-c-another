// Bellman–Ford algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int INF = 1e9;

vector<pair<int, int>> edge[MAXN];
int n, m, q;
int d[MAXN];

bool bfs(int s, int t)
{
    bool visit[MAXN];
    for (int i = 0; i < n; ++i)
        visit[i] = false;
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &it: edge[u]) {
            int v = it.first;
            if (v == t)
                return true;
            if (!visit[v]) {
                q.push(v);
                visit[v] = true;
            }
        }
    }
    return false;
}

bool bellmanFord(int s, int t)
{
    // Initialization
    for (int i = 0; i < n; ++i)
        d[i] = INF;
    d[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u)
            for (auto &it: edge[u]) {
                int v = it.first;
                int w = it.second;
                // Relax if d[v] > d[u] + w(u, v)
                if (d[u] < INF && d[v] > d[u] + w)
                    d[v] = d[u] + w;
            }
    }

    // Negative cycle detection
    for (int u = 0; u < n; ++u) {
        for (auto &it: edge[u]) {
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

    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m >> q;
        for (int i = 0; i < n; ++i)
            edge[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back({v, w});
        }

        while (q--) {
            int s, t;
            cin >> s >> t;
            if (s == t) {
                cout << "0\n";
                continue;
            }

            if (bellmanFord(s, t)) {
                if (d[t] < INF)
                    cout << d[t] << endl;
                else    // Unreachable
                    cout << "no\n";
            }
            else    // Has negative cycle
                cout << "no\n";
        }
    }
}
