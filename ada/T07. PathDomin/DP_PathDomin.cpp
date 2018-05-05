#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int main()
{
    int n;
    while (cin >> n && n) {
        int data;
        cin >> data;
        int f1[MAX], f00[MAX], f01[MAX];
        f1[0] = data;
        f00[0] = 0;
        f01[0] = INT_MAX;
        for (int i = 1; i < n; ++i) {
            cin >> data;
            f1[i] = data + min(f1[i - 1], min(f00[i - 1], f01[i - 1]));
            f00[i] = f01[i - 1];
            f01[i] = f1[i-1];
        }
        cout << min(f1[n - 1], f01[n - 1]) << endl;
    }
    return 0;
}
