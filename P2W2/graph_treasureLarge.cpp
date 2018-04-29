#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000;
const int MAX_T = 100;

int dfs(int start, vector<int> road[], int *treasure, bool *visited)
{
    int max = treasure[start];
    visited[start] = true;
    for (auto &it: road[start]) {
        if (!visited[it]) {
            int tmp = dfs(it, road, treasure, visited);
            if (tmp > max) 
                max = tmp;
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

        vector<int> road[MAX_N];
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            road[from].push_back(to);
        } 

        bool visited[MAX_N];
        memset(visited, false, sizeof(visited));
        int max = 0;
        for (int i = 0; i < t; ++i) {
            int k = start[i];
            if (visited[k])
                continue;
            int tmp = dfs(k, road, treasure, visited);
            if (tmp > max) 
                max = tmp;
        }
        cout << max << endl;
    }
    return 0;	
}