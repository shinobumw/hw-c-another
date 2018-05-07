#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n) {
        int d0 = 0, d1 = 0;    // 0: not choose, 1: choose
        int tmp0 = 0, tmp1 = 0;
        while (n--) {
            int w;
            cin >> w;
            tmp0 = max(d0, d1);
            tmp1 = w + d0;
            d0 = tmp0;
            d1 = tmp1;
        }
        cout << max(d0, d1) << '\n';
    }
    return 0;	
}
