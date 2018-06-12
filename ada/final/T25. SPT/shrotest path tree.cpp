// Dijkstra's algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int INF = 1e9;

vector<pair<int, int>> edge[MAXN];
int d[MAXN], p[MAXN];
bool intree[MAXN];

void sol(int n, int r)
{
    // Initialization
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
        d[i] = -INF;
        intree[i] = false;
        pq.push({-INF, i});
    }
    pq.push({d[r] = 0, r});
    p[r] = r;

    while (!pq.empty()) {
        pair<int, int> min = pq.top();
        pq.pop();
        int u = min.second;
        if (intree[u])
            continue;
        for (auto &it: edge[u]) {
            int v = it.second;
            int w = d[u] + it.first;
            if (!intree[v] && w >= d[v]) {
                d[v] = w;
                p[v] = u;
                pq.push({w, v});
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += d[i] - d[p[i]];
    cout << -sum << endl;
}

main()
{
    freopen("input.in", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 0; i < n; ++i)
            edge[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back({-w, v});
        }
        while (q--) {
            int r;
            cin >> r;
            sol(n, r);
        }
    }
}
