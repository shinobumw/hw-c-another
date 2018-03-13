#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1) {
        char t[10];
        fgets(t, 10, stdin);
        int n = atoi(t);
        if (n == 0) break;
        int sum = 0;

        while (n--) {
            char line[20] = {0};
            fgets(line, 20, stdin);
            int bcd = 0;
            for (int i = 0; line[i] != '\n'; ++i) {
                bcd <<= 1;
                if (line[i] == '1') bcd |= 1;
                // cout << bcd << endl;
            }
            sum += bcd;
        }
        cout << sum << '\n';
    }
    return 0;
}
