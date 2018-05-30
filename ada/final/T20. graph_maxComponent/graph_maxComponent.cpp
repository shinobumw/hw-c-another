#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50005;
vector<int> edge[MAX_N];
int weight[MAX_N];
bool visit[MAX_N];

void readGraph(int n, int m)
{
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
        edge[i].clear();
        visit[i] = false;
    }
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
}

int dfs(int s)
{
    visit[s] = true;
    int sum = weight[s];
    for (auto &it: edge[s])
        if (!visit[it])
            sum += dfs(it);
    return sum;
}

main()
{
    // freopen("input", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m;
        cin >> n >> m;
        readGraph(n, m);

        int sol = 0;
        for (int i = 0; i < n; ++i)
            if (!visit[i])
                sol = max(sol, dfs(i));
        cout << sol << '\n';
    }
}
