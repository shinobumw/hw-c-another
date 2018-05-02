#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        int parent[MAX];
        int child[MAX];
        bool covered[MAX];
        memset(child, 0, sizeof(child));
        memset(covered, false, sizeof(covered));
        parent[0] = -1;
        for (int i = 1; i < n; ++i) {
            cin >> parent[i];
            child[parent[i]]++; 
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (child[i] == 0)
                q.push(i);
        }

        vector<int> chosen;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (!covered[i] && !covered[parent[i]]) {
                covered[i] = true;
                covered[parent[i]] = true;
                chosen.push_back(parent[i]);
            }
            child[parent[i]]--;    // Remove leaf
            if (child[parent[i]] == 0 && parent[parent[i]] > -1)
                q.push(parent[i]);
        }
        cout << chosen.size() << '\n';
        // for (auto &i: chosen)
        //     cout << i << '\n';
    }
    return 0;	
}
