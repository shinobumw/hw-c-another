#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1) {
        int m, n, i;
        cin >> n >> m;    // n cells & m initial conditions
        if (n == 0) break;
        int book[2][10000], cell[10000];    // book用來記錄是否走過
        for (i = 0; i < n; ++i) cin >> cell[i];
        while (m--) {
            int dir, p;
            cin >> p >> dir;    // Initial point & Direction
            for (i = 0; i < 2; ++i)
                for (int j = 0; j < n; ++j)
                    book[i][j] = 0;

            for (i = 1;; ++i) {
                if (book[(dir + 1) / 2][p] > 0) break;    // 重複
                book[(dir + 1) / 2][p] = i;    // 將走過位置作記號
                if (cell[p] < 0) dir *= -1;    // 改變方向
                p += (dir * ((cell[p] < 0) ? -cell[p] : cell[p]));
                if (p >= n || p < 0) break;    // 越界
            }

            if (p >= n) cout << "Forward\n";
            else if (p < 0) cout << "Backward\n";
            else cout << "Cycle " << i - book[(dir + 1) / 2][p] << '\n';    // 過幾次又走回同個位置就是cycle
        }
    }
    return 0;
}