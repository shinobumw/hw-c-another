/**
 * Bellman–Ford algorithm
 * 
 * Note: Cannot handle disconnected graph with negative cycle
 *       e.g. d(u, v) is connected but other disconnected component has negative cycle
 */ 

#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0

const int MAXN = 5005;
const int MAXM = 20005;
const int INF = 1e8;

struct Edge {
    int u, v, w;
} edge[MAXM];
int n, m, q;
int d[MAXN];

/*
bool bfs(int s, int t)
{
    bool visit[MAXN];
    for (int i = 0; i < n; ++i)
        visit[i] = false;
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < m; ++i) {
            if (edge[i].u == u) {
                if (edge[i].v == t)
                    return true;
                else if (!visit[edge[i].v]) {
                    q.push(edge[i].v);
                    visit[edge[i].v] = true;
                }
            }
        }
    }
    return false;
}
*/

bool bellmanFord(int s)
{
    // Initialization
    for (int i = 0; i < n; ++i)
        d[i] = INF;
    d[s] = 0;

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            // Relax if d[v] > d[u] + w(u, v)
            if (d[edge[j].u] < INF && d[edge[j].v] > d[edge[j].u] + edge[j].w)
                d[edge[j].v] = d[edge[j].u] + edge[j].w;

    #if DEBUG == 1
    for (int i = 0; i < n; ++i)
        printf("%lld ", d[i]);
    printf("\n");
    #endif

    // Negative cycle detection
    for (int j = 0; j < m; ++j)
        if (d[edge[j].u] < INF && d[edge[j].v] > d[edge[j].u] + edge[j].w)
            return false;
    return true;
}

main()
{
    // freopen("input.in", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m >> q;
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);

        while (q--) {
            int s, t;
            cin >> s >> t;
            if (s == t) {
                cout << "0\n";
                continue;
            }

            if (bellmanFord(s)) {
                /*
                if (bfs(s, t))
                    cout << d[t] << endl;
                else    // Not reachable
                    cout << "No\n";
                */

                if (d[t] < INF)
                    cout << d[t] << endl;
                else    // Unreachable
                    cout << "no\n";
            }
            else    // Has negative cycle
                cout << "no\n";
        }
    }
}
