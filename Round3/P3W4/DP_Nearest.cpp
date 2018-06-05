#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000;

void sol(int n) 
{
    int book[MAX];
    int min_left, min_right, min_num, min = INT_MAX;
    memset(book, -1, sizeof(book));
    min_left = min_right = min_num = -1;
    
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (book[tmp] == -1)
            book[tmp] = i;
        else {
            if (min > i - book[tmp]) {
                min = i - book[tmp];
                min_left = book[tmp];
                min_right = i;
                min_num = tmp;
            }
            book[tmp] = i;
        }
    }

    if (min_num != -1)
        printf("(%d,%d):%d\n", min_left, min_right, min_num);
    else 
        printf("No solution\n");
}

main()
{
    // freopen("input_sequence", "r", stdin);

    int n;
    while (cin >> n && n) {
        sol(n);
    }
}
