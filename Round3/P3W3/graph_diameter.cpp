#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

void sol()
{
    int n;
    cin >> n;
    vector<int> edge[MAX];
    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    bool visited[MAX] = {false};
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int v;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int &u: edge[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }

    int distance[MAX] = {0};
    int diameter = 0;
    memset(visited, false, sizeof(visited));
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int &u: edge[v]) {
            if (!visited[u]) {
                distance[u] = distance[v] + 1;
                diameter = max(diameter, distance[u]);
                q.push(u);
                visited[u] = true;
            }
        }
    }

    cout << diameter << '\n';
}

int main()
{
    // freopen("input", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        sol();
    }
    return 0;
}
