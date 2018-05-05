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
		bool mark[MAX] = {false};
		for (int i = 1; i < n; ++i)
			cin >> parent[i];
		
		int cnt = 0;
		for (int i = n - 1; i > 0; --i) {
			if (!mark[i])
				mark[parent[i]] = true;
			else
				cnt++;
		}
		cnt += mark[0];

		cout << cnt << '\n';
	}
	return 0;	
}
