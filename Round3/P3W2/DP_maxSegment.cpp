#include <bits/stdc++.h>
using namespace std;

int sol(int n)
{
    int *num = new int[n+1];
    for (int i = 1; i <= n; ++i)
        cin >> num[i];
    int *prefix_sum = new int[n+1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i-1] + num[i];

    int *prefix_min = new int[n+1];
    prefix_min[0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        prefix_min[i] = min(prefix_min[i-1], prefix_sum[i]);
        ans = max(ans, prefix_sum[i] - prefix_min[i-1]);
    }

    return ans;
}

main()
{
   int testcase, n;
   cin >> testcase;
   while (testcase--) {
       cin >> n;
       cout << sol(n) << endl;
   }
}
