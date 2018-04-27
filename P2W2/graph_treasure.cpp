#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200;
const int MAX_T = 100;

int dfs(int start, int road[][MAX_N], int *treasure, bool *visited)
{
    int max = treasure[start];
    while (!visited[start]) {
        visited[start] = true;
        for (int i = 0; i < MAX_N; ++i) {
            if (road[start][i] && !visited[i]) {
                int tmp = dfs(i, road, treasure, visited);
                if (tmp > max) max = tmp;
            }
        }
    }
    return max;
}

int main()
{
    // freopen("graph_input", "r", stdin);
    int n, m, t;
    while (cin >> n >> m >> t && n && m && t) {
        // Read input
        int start[MAX_T];
        for (int i = 0; i < t; ++i) 
            cin >> start[i];

        int treasure[MAX_N];
        for (int i = 0; i < n; ++i) 
            cin >> treasure[i];

        int road[MAX_N][MAX_N];
        memset(road, 0, sizeof(road));
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            road[u][v] = 1;
        } 

        bool visited[MAX_N];
        memset(visited, false, sizeof(visited));
        int max = dfs(start[0], road, treasure, visited);
        for (int i = 1; i < t; ++i) {
            int tmp = dfs(start[i], road, treasure, visited);
            if (tmp > max) max = tmp;
        }
        cout << max << endl;
    }
    return 0;	
}
