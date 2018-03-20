#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int m, box[1000], i;
		cin >> m;
		for (i = 0; i < m; ++i) cin >> box[i];
		sort(box, box + m);

		int sum = 0, temp = 0;
		for (i = 0; i < m; ++i) {
			sum += temp * 2 + box[i];
			temp += box[i];
		}
		cout << sum << '\n';
	}
	return 0;	
}
