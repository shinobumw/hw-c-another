#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1) {
        int m, n, i;
        cin >> n >> m;
        if (n == 0) break;
        int book[2][10000], cell[10000];
        for (i = 0; i < n; ++i) cin >> cell[i];
        for (; m > 0; --m) {
            int direction, p;
            cin >> p >> direction;
            for (i = 0; i < 2; ++i)
                for (int j = 0; j < n; ++j)
                    book[i][j] = 0;

            for (i = 1;; ++i) {
                if (book[(direction + 1) / 2][p] > 0) break;
                book[(direction + 1) / 2][p] = i;
                if (cell[p] < 0) direction *= -1;
                p += (direction * ((cell[p] < 0) ? -cell[p] : cell[p]));
                if (p >= n || p < 0) break;
            }

            if (p >= n) cout << "Forward\n";
            else if (p < 0) cout << "Backward\n";
            else cout << "Cycle " << i - book[(direction + 1) / 2][p] << '\n';
        }
    }
    return 0;
}