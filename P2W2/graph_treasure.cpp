#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, t;
	while (cin >> n >> m >> t && n && m && t) {
		// Read input
		int start[200];
		for (int i = 0; i < t; ++i) 
			cin >> start[i];

		int treasure[200];
		for (int i = 0; i < n; ++i) 
			cin >> treasure[i];

		int road[4][4];
		memset(road, 0, sizeof(road));
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			road[a][b] = 1;
		} 

		bool visited[m] = {false};
		cout << dfs() << endl;
	}
	return 0;	
}
