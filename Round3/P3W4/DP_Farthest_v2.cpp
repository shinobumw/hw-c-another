#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000;

void sol(int n) 
{
    int book[MAX];
    int max_left, max_right, max_num, max;
    memset(book, -1, sizeof(book));
    max_left = max_right = max_num = max = -1;
    
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (book[tmp] == -1)
            book[tmp] = i;
        else {
            if (max < i - book[tmp]) {
                max = i - book[tmp];
                max_left = book[tmp];
                max_right = i;
                max_num = tmp;
            }
        }
    }

    if (max_num != -1)
        printf("(%d,%d):%d\n", max_left, max_right, max_num);
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
