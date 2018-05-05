#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    char buffer[101];
    gets(buffer);
    gets(buffer);
    while (testcase--) {
        vector<pair<int, int>> babysitter;
        gets(buffer);
        while (buffer[0] != 0) {
            int a, b;
            sscanf(buffer, "%d %d", &a, &b);
            if (a > b)
                babysitter.push_back(make_pair(b, a));
            else
                babysitter.push_back(make_pair(a, b));

            if (gets(buffer) == NULL)
                break;
        }

        sort(babysitter.begin(), babysitter.end());

        int i = 0;
        int left = 0, max_r = 0, cnt = 0;
        while (left < 200) {
            for (; babysitter[i].first <= left; ++i) {
                if (babysitter[i].second > max_r) 
                    max_r = babysitter[i].second;
            }
            left = max_r + 1;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;	
}