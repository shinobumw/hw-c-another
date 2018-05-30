#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        int t[1000];
        for (int i = 0; i < n; ++i)
            cin >> t[i];

        sort(t, t + n);

        int tmp = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += t[i] + 2 * tmp;
            tmp += t[i];
        }
        cout << sum << '\n';
    }
    return 0;
}
