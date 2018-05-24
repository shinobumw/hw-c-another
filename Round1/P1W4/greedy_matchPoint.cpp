#include <bits/stdc++.h>
using namespace std;

int convert(char line[], int num[])
{
	int count = 0;
	char *token = strtok(line, " \0");
	while (token != NULL) {
		num[count++] = atoi(token);
		token = strtok(NULL, " \0");
	}
	return count;
}

int main()
{
	int n;
	char line[10000];
	cin >> n;
	fgets(line, 10000, stdin);
	while (n--) {
		int x[10000], y[10000], count = 0;
		fgets(line, 10000, stdin);
		count = convert(line, x);
		fgets(line, 10000, stdin);
		count = convert(line, y);
	
		for (int i = 0; i < count; ++i) {
			x[i] = abs(x[i]);
		    y[i] = - abs(y[i]);
		}
		sort(x, x + count);
		sort(y, y + count);

		double sum = 0;
		for (int i = 0; i < count; ++i) {
			sum += sqrt(x[i] * x[i] + y[i] * y[i]);	
		}
		cout << (int)sum << '\n';
	}
	return 0;	
}
