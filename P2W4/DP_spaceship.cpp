#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int main()
{
    // freopen("input_spaceship", "r", stdin);

    int n;
    while (cin >> n && n) {
        int k1, k2;
         cin >> k1 >> k2;

        int dp1 = abs(k1 - 1000);
        int dp2 = abs(k2 - 1000);

        int tmp1 = k1;
        int tmp2 = k2;
        for (int i = 1; i < n; ++i) {
            cin >> k1 >> k2;
            int x1 = dp1 + abs(k1 - tmp1);
            int y1 = dp2 + abs(k1 - tmp2);
            int x2 = dp1 + abs(k2 - tmp1);
            int y2 = dp2 + abs(k2 - tmp2);

            tmp1 = k1;
            tmp2 = k2;

            dp1 = min(x1, y1);
            dp2 = min(x2, y2);
        }
        cout << min(dp1, dp2) << '\n';
    }
    return 0;
}
