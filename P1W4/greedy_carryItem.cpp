#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int item[10000], student[10000];
		for (int i = 0; i < n; ++i) cin >> item[i];
		for (int i = 0; i < m; ++i) cin >> student[i];

		sort(item, item + n);
		sort(student, student + m);

		int cost = 0;
		for (int i = 0, j = 0; j < n; ++i, ++j) {
			while (student[i] < item[j] && i < m) i++;
			if (i >= m) {
				cost = -1;
				break;
			}
			cost += student[i];
		}
		cout << cost << '\n';
	}
	return 0;	
}
