#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5001;

int sol()
{
    int n;
    cin >> n;
    int parent[MAX_N], edge[MAX_N];
    int degree[MAX_N] = {0};
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
        degree[parent[i]]++;
    }
    for (int i = 2; i <= n; ++i)
        cin >> edge[i];

    queue<int> q;
    for (int i = 2; i <= n; ++i)
        if (degree[i] == 0)
            q.push(i);

    int num_of_node[MAX_N];
    for (int i = 1; i <= n; ++i) 
        num_of_node[i] = 1;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        int p = parent[c];
        num_of_node[p] += num_of_node[c];
        degree[p]--;
        if (degree[p] == 0)
            q.push(p);
    }

    int sum = 0;
    for (int i = 2; i <= n; ++i)
        sum += 2 * num_of_node[i] * (n - num_of_node[i]) * edge[i];
    return sum;
}

main()
{
    // freopen("input_graph", "r", stdin);

    int t;
    cin >> t;
    while (t--)
        cout << sol() << '\n';
}
