// Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

vector<pair<int, int>> edge[MAXN];
int d[MAXN];
bool intree[MAXN];

void prim(int n)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
        intree[i] = false;
    for (int i = 1; i < n; ++i) {
        d[i] = INT_MIN;
        pq.push({INT_MIN, i});
    }
    pq.push({d[0] = 0, 0});

    int sol = 0, u, v, w;
    while (!pq.empty()) {
        pair<int, int> min = pq.top();
        pq.pop();
        w = min.first;
        u = min.second;
        if (intree[u])
            continue;
        sol += w;
        intree[u] = true;
        for (auto &it: edge[u]) {
            w = it.first;
            v = it.second;
            if (!intree[v] && w > d[v]) {
                d[v] = w;
                pq.push(it);
            }
        }
    }
    cout << -sol << endl;
}

main()
{
    // freopen("input.in", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            edge[i].clear();
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            // cin would lead to TLE
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back({-w, v});
            edge[v].push_back({-w, u});
        }
        prim(n);
    }
}
