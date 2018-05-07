#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int tf0[MAX], tf1[MAX];
int w[MAX];

void sol()
{
    int n;
        cin >> n >> w[1];

        int parent[MAX], degree[MAX];
        for (int i = 1; i <= n; ++i)
            degree[i] = 0;

        for (int i = 2; i <= n; ++i) {
            cin >> parent[i] >> w[i];
            degree[parent[i]]++;
        }

        for (int i = 1; i <= n; ++i)
            tf0[i] = 0;
        for (int i = 1; i <= n; ++i)
            tf1[i] = w[i];

        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (degree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int p = parent[v];
            tf0[p] += max(tf0[v], tf1[v]);
            tf1[p] += tf0[v];
            degree[p]--;
            if (degree[p] == 0)
                q.push(p);
        }
        cout << max(tf0[1], tf1[1]) << '\n';
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
