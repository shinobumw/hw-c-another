#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        int parent[MAX];
        bool covered[MAX];
        memset(covered, false, sizeof(covered));
        parent[0] = -1;
        for (int i = 1; i < n; ++i) {
            cin >> parent[i]; 
        }

        int count = 0;
        for (int i = n - 1; i > 0; --i) {
            int p = parent[i];
            if (!covered[i] && !covered[p]) {
                // covered[i] = true;    // Optional
                covered[p] = true;
                count++;
            }		
        }
        cout << count << '\n';
    }
    return 0;	
}
