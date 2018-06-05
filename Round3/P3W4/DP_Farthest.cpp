#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000;

void sol(int n) 
{
    int first[MAX], last[MAX];
    memset(first, -1, sizeof(first));
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (first[num] == -1)
            first[num] = i;
        last[num] = i;
    }

    int fir, sec, num, farthest;
    fir = sec = num = farthest = -1;
    for (int i = 0; i < MAX; ++i) {
        if (first[i] == -1 || first[i] == last[i])
            continue;
        if (farthest < last[i] - first[i]) {
            farthest = last[i] - first[i];
            fir = first[i];
            sec = last[i];
            num = i;
        }
        else if (farthest == last[i] - first[i] && first[i] < fir){
            fir = first[i];
            sec = last[i];
            num = i;
        }
    }

    if (num > -1)
        printf("(%d,%d):%d\n", fir, sec, num);
    else 
        cout << "No solution\n";
}

main()
{
    // freopen("input_sequence", "r", stdin);

    int n;
    while (cin >> n && n) {
        sol(n);
    }
}
