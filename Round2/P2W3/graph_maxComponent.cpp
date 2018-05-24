#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50000;

vector<int> graph[MAX_N];
bool visited[MAX_N];
int weight[MAX_N];

void readGraph(int n, int m) 
{
    for (int i = 0; i < n; ++i){
        graph[i].clear();
        visited[i] = false;
    }

    for (int i = 0; i < n; ++i)
        cin >> weight[i];

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int sum = weight[start];
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (auto &j: graph[i]) {
            if (visited[j]) 
                continue;
            visited[j] = true;
            q.push(j);
            sum += weight[j];
        }			
    }
    return sum;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n, m;
        cin >> n >> m;
        readGraph(n, m);

        int sol = -1, tmp;
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                tmp = bfs(i);
            sol = max(sol, tmp);
        }
        cout << sol << '\n';
    }
    return 0;	
}
