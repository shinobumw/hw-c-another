#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

void sol()
{
    int n, m;
    cin >> n >> m;

    int total = 0;
    bool flag[MAX] = {false};
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        for (int j = total; j > 0; --j) {
            if (flag[j])
                flag[j+w] = true;
        }
        flag[w] = true;
        total += w;
    }

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int item;
        cin >> item;
        if (flag[item])
            cnt++;
    }
    cout << cnt << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
