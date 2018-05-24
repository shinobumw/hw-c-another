#include <bits/stdc++.h>
using namespace std;

int jobTime(vector<int> job, int n, int m)
{
    priority_queue<int, vector<int>, greater<int>> machine;
    for (int i = 0; i < m; ++i)
        machine.push(0);

    for (int i = 0; i < n; ++i) {
        int tmp = machine.top();
        machine.pop();
        machine.push(tmp + job[i]);
    }

    for (int i = 0; i < m - 1; ++i)
        machine.pop();
    return machine.top();
}

void sol()
{
    int n, deadline;
    cin >> n >> deadline;
    vector<int> job;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        job.push_back(tmp);
        sum += tmp;
        if (tmp > deadline) {
            cout << "-1\n";
            return;
        }
    }

    int left = sum / deadline;
    int right = n;
    int mid, pivot;
    while (left < right) {
        mid = (left + right) / 2;
        pivot = jobTime(job, n, mid);
        if (pivot > deadline)
            left = mid + 1;
        else
            right = mid;
    }

    cout << right << endl;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--) {
        sol();
    }
    return 0;	
}