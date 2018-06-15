#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXM = 500005;

struct Edge {
    int u, v, w;
} e[MAXM];
int p[MAXN];

bool cmp(Edge &e1, Edge &e2)
{
    return e1.w < e2.w;
}

int find(int x)
{
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b)
{
    int r1 = find(a);
    int r2 = find(b);
    p[r1] = r2;
}

main()
{
    // freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
            p[i] = -1;
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

        sort(e, e + m, cmp);

        int sum = 0;
        for (int i = 0; i < m, n > k; ++i) {
            int u = e[i].u;
            int v = e[i].v;
            int w = e[i].w;
            if (find(u) != find(v)) {
                uni(u, v);
                n--;
                sum += w;
            }
        }
        cout << sum << endl;
    }
}
