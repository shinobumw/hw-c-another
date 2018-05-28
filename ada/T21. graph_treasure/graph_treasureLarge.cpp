#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5001;
const int MAX_T = 101;

vector<int> edge[MAX_N];
int start[MAX_T], treasure[MAX_N];
bool visit[MAX_N];

void read(int n, int m, int t)
{
    for (int i = 0; i < t; ++i)
        cin >> start[i];
    for (int i = 0; i < n; ++i) {
        cin >> treasure[i];
        edge[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
    }
}

int dfs(int s)
{
    visit[s] = true;
    int sol = treasure[s];
    for (auto &it: edge[s]) {
        if (!visit[it])
            sol = max(sol, dfs(it));
    }
    return sol;
}

main()
{
    // freopen("input", "r", stdin);

    int n, m, t;
    while (cin >> n >> m >> t && n && m && t) {
        read(n, m, t);

        int sol = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < t; ++i) {
            int s = start[i];
            if (!visit[s])
                sol = max(sol, dfs(s));
        }
        cout << sol << endl;
    }
}
