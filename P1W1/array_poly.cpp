#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    while (num--) {
        long base[3], d, expo, temp[2048], result[2048];
        int count = 2;
        memset(base, 0, sizeof(base));
        memset(temp, 0, sizeof(temp));
        memset(result, 0, sizeof(result));

        cin >> base[2] >> base[1] >> base[0] >> d;
        expo = d;
        for (int i = 0; i < 3; ++i)
            temp[i] = base[i];

        while (--expo) {
            memset(result, 0, sizeof(result));
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j <= count; ++j) {
                    result[i + j] += (base[i] * temp[j]);
                }
            }
            count += 2;

            for (int i = 0; i <= count; ++i)
                temp[i] = result[i];
        }

        if (d != 1) {
            for (int i = count; i >= 0; --i)
                cout << result[i] << ((i) ? " " : "");
        }
        else {
            for (int i = 2; i >= 0; --i)
                cout << base[i] << ((i) ? " " : "");
        }
        cout << endl;
    }

    return 0;
}