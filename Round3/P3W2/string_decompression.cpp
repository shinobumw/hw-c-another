#include <bits/stdc++.h>
using namespace std;

const int MAX = 2048;

main()
{
    char line[MAX];
    while (cin >> line) {
        int len = strlen(line);
        int cnt[MAX];
        int i, j = 0;
        for (i = 0; i < len; ++i)
            if (isdigit(line[i]))
                cnt[j++] = line[i] - '0';

        char delim[] = "123456789";
        char *token = strtok(line, delim);
        j = 0;
        while (token != NULL) {
            while (cnt[j]--)
                cout << token;
            j++;
            token = strtok(NULL, delim);
        }
        cout << endl;
    }
}
