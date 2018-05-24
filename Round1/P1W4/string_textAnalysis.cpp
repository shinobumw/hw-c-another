#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("string_textAnalysis_input.txt", "r", stdin);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string line;
        getline(cin, line);

        int len = line.size();
        int alphabet[26];
        memset(alphabet, 0, sizeof(alphabet));
        for (int i = 0; i < len; ++i) {
            line[i] = toupper(line[i]);
            if (isalpha(line[i])) alphabet[line[i] - 'A']++;
        }

        int max = alphabet[0];
        for (int i = 0; i < 26; ++i)
            if (max < alphabet[i])
                max = alphabet[i];
        for (int i = 0; i < 26; ++i)
            if (alphabet[i] == max)
                cout << (char)(i + 'A');
        cout << '\n';
    }
    return 0;
}