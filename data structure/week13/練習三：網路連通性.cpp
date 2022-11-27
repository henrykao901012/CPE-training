#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a[100][100], get[100] = {0};
    get[0] = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n && get[i]; i++)
        for (int j = 0; j < n; j++)
            get[j] |= a[i][j];

    bool ans = 1;
    for (int i = 0; i < n; i++)
        ans &= get[i];

    cout << (ans ? 1 : -1) << "\n";

    system("pause");
    return 0;
}