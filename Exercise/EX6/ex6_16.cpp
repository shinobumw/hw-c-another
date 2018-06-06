#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define DEBUG 2

const int MAX_N = 16;

struct Board {
    int row;    // Record current row
    int cost;    // Record current cost(by row)
    int position[MAX_N][MAX_N];    // 0: Forbidden, 1: Allowed, 2: Placed
};

int sol;
int weight[MAX_N][MAX_N];

int upperbound(Board b, int n)
{
    int max_row = 0, max_col = 0, tmp_col[MAX_N];
    memset(tmp_col, INT_MIN, sizeof(tmp_col));
    for (int i = b.row; i < n; ++i) {
        int tmp_row = INT_MIN;
        for (int j = 0; j < n; ++j) {
            if (b.position[i][j]) {
                tmp_row = max(tmp_row, weight[i][j]);
                tmp_col[j] = max(tmp_col[j], weight[i][j]);
            }
        }
        max_row += tmp_row;
    }

    sort(tmp_col, tmp_col + n);
    for (int j = b.row; j < n; ++j)
        max_col += tmp_col[j];

    return min(max_row, max_col);
}

void nQueens(Board b_origin, int n)
{
    if (b_origin.row == n) {
        sol = max(sol, b_origin.cost);
        return;
    }

    // Cut
    if (b_origin.cost + upperbound(b_origin, n) <= sol)
        return;

    int i, j, k;
    for (j = 0; j < n; ++j) {
        if (b_origin.position[b_origin.row][j]) {
            Board b = b_origin;
            b.position[b.row][j] = 2;    // Place queen
            b.cost += weight[b.row][j];
            b.row++;

            // Ban column
            for (i = b.row; i < n; ++i)
                b.position[i][j] = 0;

            // Ban diagonal
            i = b.row;
            k = j + 1;
            while (i < n && k < n)
                b.position[i++][k++] = 0;

            i = b.row;
            k = j - 1;
            while (i < n && k >= 0)
                b.position[i++][k--] = 0;

            nQueens(b, n);
        }
    }
}

int main()
{
    #if DEBUG == 1
    freopen("exe6_sample.in", "r", stdin);
    #endif
    #if DEBUG == 2
    freopen("eq_16.in", "r", stdin);
    #endif
    #if DEBUG == 3
    freopen("eq_20.in", "r", stdin);
    #endif

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> weight[i][j];

        // Initialization
        sol = INT_MIN;
        Board b;
        memset(b.position, 1, sizeof(b.position));
        b.row = b.cost = 0;

        // Find max
        nQueens(b, n);
        cout << sol << " ";

        // Find min
        sol = INT_MIN;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                weight[i][j] *= -1;    // Inverse
        nQueens(b, n);
        cout << -sol << endl;
    }
    return 0;
}
