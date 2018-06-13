#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

vector<int> edge[MAXN];
int *mx, *my;
bool *visit;

bool dfs(int x)
{
    for (auto &y: edge[x]) {
        if (!visit[y]) {
            visit[y] = true;
            if (my[y] == -1 || dfs(my[y])) {
                // Flip
                mx[x] = y;
                my[y] = x;
                return true;
            }
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
        visit = new bool[ny];
        mx = new int[nx];
        my = new int[ny];
        fill(mx, mx + nx, -1);
        fill(my, my + ny, -1);

        int cardinality = 0;
        for (int x = 0; x < nx; ++x) {
            for (int y = 0; y < ny; ++y)
                visit[y] = false;
            if (dfs(x))
                cardinality++;
        }

        cout << cardinality << endl;
    }
}
