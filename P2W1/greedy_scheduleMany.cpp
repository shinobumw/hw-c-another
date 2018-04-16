#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcase;
    cin >> testcase;
	while (testcase--) {
		int n, m;
		cin >> n >> m;

		int job, t[10];
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; ++i) {
			cin >> job;
			int min = 0;
			for (int j = 1; j < m; ++j)
				if (t[min] > t[j]) 
					min = j;
			t[min] += job;
		}

		int max = 0;
		for (int i = 1; i < m; ++i) {
			if (t[max] < t[i])
				max = i;
		}
		cout << t[max] << endl;
	}
	return 0;
}