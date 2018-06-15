#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
const int INF = 1e9;

vector<pair<int, int>> e[MAX];
bool intree[MAX];
int d[MAX], n, m, q;
int p[MAX];

void sol(int r)
{
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
        intree[u] = true;
        for (auto &it: e[u]) {
            int v = it.second;
            int w = d[u] + it.first;
            if (!intree[v] && d[v] <= w) {
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
            e[u].push_back({-w, v});
        }

        while (q--) {
            int r;
            cin >> r;
            sol(r);
        }
    }
}
