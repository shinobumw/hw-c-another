#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input", "r", stdin);

	int testcase;
    cin >> testcase;
	while (testcase--) {
        int n = 0;
        cin >> n;
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            left.push_back(a);
            right.push_back(b);
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int thick = 0, sol = 0, j = 0;
        for (auto &i: left) {
            while (j < n && right[j] < i) {
                j++;
                thick--;
            }
            thick++;
            sol = max(sol, thick);
        }
        cout << sol << endl;
	}
	return 0;
}
