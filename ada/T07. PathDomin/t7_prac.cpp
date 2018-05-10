#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;

int main()
{
    int n;
    while (cin >> n && n) {
        int w;
        cin >> w;

        int dp00[505], dp01[505], dp1[505];
        dp1[0] = w;
        dp00[0] = 0;
        dp01[0] = 2000;

        int i;
        for (i = 1; i < n; ++i) {
            cin >> w;
            dp1[i] = w + min(dp1[i-1], min(dp00[i-1], dp01[i-1])); 
            dp00[i] = dp01[i-1];
            dp01[i] = dp1[i-1];
        }
        cout << min(dp01[n-1], dp1[n-1]) << '\n';
    }
    return 0;
}
