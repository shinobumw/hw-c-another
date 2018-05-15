#include <bits/stdc++.h>
using namespace std;

bool sol()
{
    int a, b, c, d;
    int mpa, mpb, mpc;
    cin >> d
        >> a >> b >> c
        >> mpa >> mpb >> mpc;

    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            for (int k = 0; k <= c; ++k)
                if (d == i*mpa + j*mpb + k*mpc)
                    return true;
    
    return false;
}

main()
{
    int t;
    cin >> t;
    while (t--) {
        bool isAble = sol();
        if (isAble)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
