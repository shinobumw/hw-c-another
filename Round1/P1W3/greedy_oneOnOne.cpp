#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int enemy[10001], soldier[10001];
        for (int i = 0; i < n; ++i) cin >> enemy[i];
        for (int i = 0; i < n; ++i) cin >> soldier[i];
        sort(enemy, enemy + n);
        sort(soldier, soldier + n);
                
        int i = 0, j = 0, win = 0;
        while (i < n) {
            while ((soldier[i] <= enemy[j]) && (i < n)) i++;
            if (i == n) break;
            win++;
            i++; 
            j++;
        }
        cout << win << '\n';
    }    
    return 0;
}