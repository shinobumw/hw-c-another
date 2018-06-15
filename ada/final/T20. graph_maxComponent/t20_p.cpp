#include <bits/stdc++.h>
using namespace std;

const int MAX = 50005;

vector<int> e[MAX];
int w[MAX];
bool vis[MAX];

int dfs(int s)
{
    vis[s] = true;
    int sum = w[s];
    for (auto &it: e[s])
        if (!vis[it])
            sum += dfs(it);
    return sum;
}

main()
{
    // freopen("input", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            e[i].clear();
            vis[i] = false;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, & b);
            e[a].push_back(b);
            e[b].push_back(a);
        }

        int sol = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i])
                sol = max(sol, dfs(i));
        }
        cout << sol << endl;
    }
}
