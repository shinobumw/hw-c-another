#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n) {
        int dp0 = 0;
        int dp1 = 0;
        int tmp0 = 0;
        int tmp1 = -1;

        for (int i = 0; i < n; ++i) {
            int w;
            cin >> w;

            dp0 = max(tmp0, tmp1);
            dp1 = w + tmp0; 

            tmp0 = dp0;
            tmp1 = dp1;
        }
        cout << max(dp0, dp1) << '\n';
    }
    return 0;
}
