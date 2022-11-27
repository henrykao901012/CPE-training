#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull fib(int n)
{
    return n == 1 ? 1 : (n == 0 ? 0 : fib(n - 1) + fib(n - 2));
}

int main()
{
    int n;
    cin >> n;

    cout << fib(n) << "\n";

    system("pause");
    return 0;
}
