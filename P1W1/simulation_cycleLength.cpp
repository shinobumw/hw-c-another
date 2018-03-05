#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    while (1) {
        long long p, q;
        cin >> p >> q;
        if (q == 0) break;

        int *book = new int[1000100];
        memset(book, 0, sizeof(book));

        int i;
        for (i = 1; ; ++i) {
            if (book[p] > 0) break;
            // Record the remainder's position.
            book[p] = i;
            p = (p * 10) % q;
        }
        // Cycle length = end - begin
        cout << (i - book[p]) << endl;

        delete book;
    }

    return 0;
}
