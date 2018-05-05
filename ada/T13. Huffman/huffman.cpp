#include <bits/stdc++.h>
using namespace std;

typedef long long ll;    // Be careful of the range

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            ll frequency;
            cin >> frequency;
            pq.push(frequency);
        }

        ll sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x = pq.top();
            pq.pop();
            x += pq.top();
            pq.pop();
            sum += x;
            pq.push(x);
        }
        cout << sum << '\n';
    }
    return 0;
}