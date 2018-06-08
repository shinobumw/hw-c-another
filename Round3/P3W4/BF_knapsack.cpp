#include <bits/stdc++.h>
using namespace std;

const int MAX = 25;

int N, L, A, B, sol;
int value[MAX], weight[MAX];

void dfs(int lv, int cnt, int v, int w)
{
    if (w > B)
        return;

    if (lv == N) {
        if (cnt >= L && w >= A) {
            int tmp = v / w;
            if (tmp * w != v)
                tmp++;
            sol = max(sol, tmp);
        }
        return;
    }

    dfs(lv + 1, cnt + 1, v + value[lv], w + weight[lv]);
    dfs(lv + 1, cnt, v, w);
}

main()
{
    // freopen("input", "r", stdin);

    while (cin >> N >> L >> A >> B) {
        for (int i = 0; i < N; ++i)
            cin >> value[i] >> weight[i];

        sol = -1;
        dfs(0, 0, 0, 0);
        cout << sol << endl;

        int terminal;
        cin >> terminal;
        if (terminal == -1)
            break;
    }
}
