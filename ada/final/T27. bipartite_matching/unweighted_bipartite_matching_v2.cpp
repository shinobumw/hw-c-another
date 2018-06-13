// Augmenting path algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXV = 505;

vector<int> edge[MAXV];
int mx[MAXV], my[MAXV];
bool visit[MAXV];

bool dfs(int x)
{
    visit[x] = true;
    for (auto &y: edge[x]) {
        // Find augmenting path: 
        // (y is unmatched) or (y's matching point has augmenting path(unmatching point)) 
        if (my[y] == -1 || !visit[my[y]] && dfs(my[y])) {
            mx[x] = y;
            my[y] = x;
            return true;
        }
    }
    return false;
}

main()
{
    // freopen("input.in", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int nx, ny, m;
        cin >> nx >> ny >> m;

        // Initialization
        for (int i = 0; i < nx; ++i)
            edge[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            edge[a].push_back(b);
        }
        fill(mx, mx + nx, -1);
        fill(my, my + ny, -1);

        int cardinality = 0;
        for (int x = 0; x < nx; ++x) {
            fill(visit, visit + ny, false);
            if (dfs(x))
                cardinality++;
        }

        cout << cardinality << endl;
    }
}
