#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
const int INF = 1e9;

vector<pair<int, int>> e[MAX];
bool intree[MAX];
int d[MAX];

void sol(int n)
{
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < n; ++i) {
        d[i] = -INF;
        pq.push({-INF, i});
    }
    pq.push({d[0] = 0, 0});

    int sum = 0, u, v, w;
    while (!pq.empty()) {
        pair<int, int> min = pq.top();
        pq.pop();
        w = min.first;
        u = min.second;
        if (intree[u])
            continue;
        sum += w;
        intree[u] = true;
        for (auto &it: e[u]) {
            w = it.first;
            v = it.second;
            if (!intree[v] && d[v] <= w) {
                d[v] = w;
                pq.push(it);
            }
        }
    }
    cout << -sum << endl;
}

main()
{
    // freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            e[i].clear();
            intree[i] = false;
        }

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[u].push_back({-w, v});
            e[v].push_back({-w, u});
        }

        sol(n);
    }
}
