#include <bits/stdc++.h>
using namespace std;

main()
{
    int n;
    int cnt = 0;
    while (cin >> n && n) {
        cnt++;
        int h[51], avg = 0;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            avg += h[i];
        }
        avg /= n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] > avg)
                ans += (h[i] - avg);
        }

        cout << "Set #" << cnt << endl;
        cout << "The minimum number of moves is " << ans << ".\n";
        cout << endl;
    }
}
