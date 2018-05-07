// Weighted Activity Selection Problem

#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

struct Segment {
    int left;
    int right;
    int weight;
};

bool cmp(const Segment a, const Segment b)
{
    return a.right < b.right;
}

int sol(vector<Segment> job, int n)
{
    int dp[MAX];
    map<int, int, greater<int>> m;
    m.insert(make_pair(0, dp[0] = 0));
    for (int i = 1; i <= n; ++i) {
        auto it = m.lower_bound(job[i].left);
        dp[i] = max(dp[i - 1], job[i].weight + it->second);
        it = m.insert(m.begin(), {job[i].right, dp[i]});
        it->second = max(it->second, dp[i]);
    }

    return dp[n];
}

int main()
{
    // freopen("input", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        vector<Segment> job;
        job.push_back({0, 0, 0});
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int l, r, w;
            cin >> l >> r >> w;
            job.push_back({l, r, w});
        }

        sort(job.begin(), job.end(), cmp);

        cout << sol(job, n) << '\n';
    }
    return 0;
}
