#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int width;
    int length;
};

bool cmp(Rectangle x, Rectangle y)
{
    if (x.width == y.width)
        return x.length < y.length;
    else
        return x.width < y.width;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        vector<Rectangle> tile;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            tile.push_back({x, y});
            tile.push_back({y, x});
        }
        
        sort(tile.begin(), tile.end(), cmp);

        // for (auto &it: tile) cout << it.width << ":" << it.length << '\n';

        unsigned int i = 0, sum = 0;
        for (i = 0; i < tile.size() - 1; ++i) {
            if (tile[i].width != tile[i+1].width)
                sum += tile[i].length;
        }
        sum += tile[i].length;

        cout << sum << '\n';
    }
    return 0;
}