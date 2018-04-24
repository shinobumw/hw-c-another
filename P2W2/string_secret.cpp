#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Table
	char lowercase[26];
	char uppercase[26];
	int digit[10];

	for (int i = 0; i < 26; ++i) {
		lowercase[i] = 'Z' - i;
		uppercase[i] = 'z' - i;
	}

	for (int i = 0; i < 10; ++i) {
		if (i != 9)
			digit[i] = i + 1;	
		else
			digit[i] = 0;
	}

	int ch;
	while ((ch = getchar()) != EOF) {
		if (isdigit(ch))
			cout << digit[ch-'0'];
		else if (isalpha(ch)) {
			if (isupper(ch))
				cout << uppercase[ch-'A'];
			else
				cout << lowercase[ch-'a'];
		}
		else
			cout << (char)ch;
	}
	return 0;	
}
