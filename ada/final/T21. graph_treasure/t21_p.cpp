#include <bits/stdc++.h>
using namespace std;

const int MAX = 5005;

vector<int> e[MAX];
int w[MAX], start[MAX];
bool vis[MAX];

int dfs(int s)
{
    vis[s] = true;
    int sol = w[s];
    for (auto &it: e[s])
        if (!vis[it])
            sol = max(sol, dfs(it));
    return sol;
}

main()
{
    // freopen("input", "r", stdin);

    int n, m, t;
    while (cin >> n >> m >> t && n && m && t) {
        for (int i = 0; i < t; ++i)
            scanf("%d", &start[i]);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            e[i].clear();
            vis[i] = false;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            e[a].push_back(b);
        }

        int sol = 0;
        for (int i = 0; i < t; ++i) {
            int s = start[i];
            if (!vis[s])
                sol = max(sol, dfs(s));
        }
        cout << sol << endl;
    }
}
