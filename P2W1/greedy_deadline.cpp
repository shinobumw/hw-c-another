#include <bits/stdc++.h>
using namespace std;

struct WORK {
    int time;
    int deadline;
};

bool cmp(WORK a, WORK b)
{
    return a.deadline < b.deadline;
}

bool sol()
{
    int n;
    WORK job[100];

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> job[i].time;
    for (int i = 0; i < n; ++i) cin >> job[i].deadline;
    sort(job, job + n, cmp);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += job[i].time;
        if (sum > job[i].deadline)
            return false;
    }
    return true;
}

int main()
{
	int ncase;
    cin >> ncase;
	while (ncase--) {
        bool ans = sol();
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
	}
	return 0;
}
