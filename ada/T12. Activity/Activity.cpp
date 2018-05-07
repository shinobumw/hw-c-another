// Unweighted Activity Selection Problem

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        vector<pair<int, int>> activity;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int start, end;
            cin >> start >> end;
            activity.push_back(make_pair(end, start));
        }

        sort(activity.begin(), activity.end());

        int cnt = 1;
        int idx = activity[0].first;
        for (int i = 1; i < n; ++i) {
            if (activity[i].second < idx)
                continue;
            idx = activity[i].first;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
