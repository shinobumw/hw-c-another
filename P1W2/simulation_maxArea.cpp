#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int x[50], y[50], count = 0;
        for (int i = 0; i < m; ++i) {
            cin >> x[i] >> y[i];
            count++;
        }
        int area, max = 0;
        for (int i = 0; i < count - 1; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (x[i] == x[j] && y[i] == y[j])
                     area = 0;
                else
                    area = (x[j] - x[i]) * (y[j] - y[i]);
                if (area < 0) area *= -1;
                if (max < area) max = area;
            }
        }
        cout << max << endl;
    }

    return 0;
}