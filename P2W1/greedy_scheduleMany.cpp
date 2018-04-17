#include <bits/stdc++.h>
using namespace std;

int main()
{
	int testcase;
    cin >> testcase;
	while (testcase--) {
		int n, m;
		cin >> n >> m;

		int job;
		priority_queue<int> machine;
		for (int i = 0; i < m; ++i) 
			machine.push(0);
		for (int i = 0; i < n; ++i) {
			cin >> job;
			int min = machine.top();
			machine.pop();
			machine.push(min - job);
		}
		
		for (int i = 0; i < m - 1; ++i) 
			machine.pop();
		cout << -machine.top() << endl;
	}
	return 0;
}