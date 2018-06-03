#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 16;

struct Board {
    int row;
    int cost;
    int position[MAX_N][MAX_N];    // 0: Forbidden, 1: Allowed, 2: Placed
};

int sol_max, sol_min;
int weight[MAX_N][MAX_N];

void nQueens(Board b_origin, int n)
{
    if (b_origin.row == n) {
        sol_max = max(sol_max, b_origin.cost);
        sol_min = min(sol_min, b_origin.cost);
        return;
    }

    int i, j, k;
    for (j = 0; j < n; ++j) {
        if (b_origin.position[b_origin.row][j]) {
            Board b = b_origin;
            b.position[b.row][j] = 2;
            b.cost += weight[b.row][j];
            b.row++;

            // Column
            for (i = b.row; i < n; ++i)
                b.position[i][j] = 0;

            // Diagonal
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

main()
{
    // freopen("input_Branch_8Queen", "r", stdin);

    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        if (n > 1 && n < 4) {
            cout << "-1 -1\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> weight[i][j];

        sol_max = 0;
        sol_min = INT_MAX;
        Board b;
        memset(b.position, 1, sizeof(b.position));
        b.row = b.cost = 0;
        nQueens(b, n);

        cout << sol_max << " " << sol_min << endl;
    }
}
