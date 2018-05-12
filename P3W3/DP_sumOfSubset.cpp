#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n ,m;
        cin >> n >> m;

        bool flag[MAX] = {false};
        int total = 0;
        for (int i = 0; i < n; ++i) {
            int w;
            cin >> w;
            for (int j = total; j > 0; --j)
                if (flag[j])
                    flag[j+w] = true;
            flag[w] = true;
            total += w;
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            int w;
            cin >> w;
            if (flag[w])
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
