#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
map<int, int> m;

int sol(int n)
{
    int ans = 0, total = 0;
    map<int, int>::iterator it;
    m.clear();
    m.insert({-1, 0});
    for (int i = 0; i < n; ++i) {
        it = m.lower_bound(v[i].first);
        it--;
        total = v[i].second + it->second;
        ans = max(ans, total);
        it = m.insert(it, {v[i].first, total});
        if (it->second < total) {    // Compare if they have the same key value
            it->second = total;
        }
        it++;
        while (it != m.end() && it->second <= total) {
            it = m.erase(it);
        }
    }
    return ans;
}

int main()
{
    // freopen("input", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        v.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            v.push_back(make_pair(tmp, 0));
        }
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            v[i].second = tmp;
        }
        cout << sol(n) << '\n';
    }
    return 0;
}
