#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d, n, k = 1;
        cin >> d >> n;
        d--;
        while (d--)
        {
            if (n % 2)
            {
                n = n / 2 + 1;
                k = k * 2;
            }
            else
            {
                n = n / 2;
                k = k * 2 + 1;
            }
        }
        cout << k << "\n";
    }
    cin >> t;
    system("pause");
    return 0;
}