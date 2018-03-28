#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    long long sum = 0;
    for (int i = 0; i < argc; ++i)
        sum += atoi(argv[i]);
    cout << "The sum is: " << sum << '\n';
    return 0;
}