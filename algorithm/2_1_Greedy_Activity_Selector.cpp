#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, s, f, max = -1;
    while (cin >> n >> s >> f)
    {
        if (s >= max)
        {
            cout << n << " ";
            max = f;
        }
    }
    cout << "\n";

    system("pause");
    return 0;
}