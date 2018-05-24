#include <bits/stdc++.h>
using namespace std;

int mod(unsigned int x, unsigned int y, unsigned int p)
{
    if (x == 0) return 0;
    unsigned int result = 1;

    while (y) {
        if (y & 1) result = (result % p) * (x % p);
        y >>= 1;
        x = (x % p) * (x % p); 
    }
    return result % p;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        unsigned int x, y, p;
        cin >> x >> y >> p;
        cout << mod(x, y, p) << endl;
    }

    return 0;
}