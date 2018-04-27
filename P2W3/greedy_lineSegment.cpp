#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        vector<pair<int, int>> line;
        cin >> n;
        while (n--) {
            int start, end;
            cin >> start >> end;
            line.push_back(make_pair(start, end));
        }

        sort(line.begin(), line.end());

        int sum = (line[0].second - line[0].first);
        int index = line[0].second;
        for (int i = 1; i < line.size(); ++i) {
            if (line[i].first <= index && line[i].second > index)
                sum += (line[i].second - index);
            else if (line[i].first > index)
                sum += (line[i].second - line[i].first);
            else
                continue;
            index = line[i].second;
        }
        cout << sum << endl;
    }
    return 0;
}