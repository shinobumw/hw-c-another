// Kruskal's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXM = 500005;

int parent[MAXN];
struct Edge {
    int u, v, w;
} edge[MAXM];

bool cmp(Edge &e1, Edge &e2)
{
    return e1.w < e2.w;
}

// Find root that represent the disjoint set
int find(int i)
{
    if (parent[i] < 0)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int a, int b)
{
    int r1 = find(a);
    int r2 = find(b);
    parent[r1] = r2;
    /*
    if (r1 == r2)
        return;
    if (parent[r1] < parent[r2])
        parent[r2] = r1;
    else
        parent[r1] = r2;
    */
}

main()
{
    // freopen("input.in", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            parent[i] = -1;
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);

        sort(edge, edge + m, cmp);

        int sum = 0;
        for (int i = 0; i < m && n > k; ++i) {
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;

            if (find(u) != find(v)) {
                unionSets(u, v);
                n--;
                sum += w;
            }
        }
        cout << sum << endl;
    }
}
