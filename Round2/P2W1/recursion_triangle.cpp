#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		
		int seg[10000];
		memset(seg, 0, sizeof(seg));
		for (int i = 0; i < n; ++i) cin >> seg[i];
		sort(seg, seg + n);

		int count = 0;
		for (int i = 0; i < n - 2; ++i) {
			for (int j = i + 1; j < n - 1; ++j) 
				for (int k = j + 1; k < n; ++k)
					if ((seg[i] + seg[j]) > seg[k])
						count++;
		}
		cout << count << endl;
	}
	return 0;
}
