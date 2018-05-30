#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) { 
        vector<int> last;
        int len;
        cin >> len;
        for (int i = 0; i < len; ++i) {
            int n;
            cin >> n;
            auto it = lower_bound(last.begin(), last.end(), n);
            if (it == last.end())
                last.push_back(n);
            else
                *it = n;
        }
        cout << last.size() << '\n';
    }
    return 0;	
}
