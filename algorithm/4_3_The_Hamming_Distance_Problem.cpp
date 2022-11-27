#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, l, d;
    cin >> t;
    while (t--)
    {
        cin >> l >> d;
        string str = string(l - d, '0') + string(d, '1');
        do
        {
            cout << str << "\n";
        } while (next_permutation(str.begin(), str.end()));
        cout << (t ? "\n" : "");
    }

    system("pause");
    return 0;
}