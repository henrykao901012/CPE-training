#include <bits/stdc++.h>

using namespace std;
int main()
{
    int l, pri[100000] = {0}, c, p;
    cin >> l;
    while (cin >> c >> p && c)
        pri[c] = p;

    int r[100000] = {0};
    for (int i = 1; i <= l; i++)
    {
        int q = -1;
        for (int j = 1; j <= i; j++)
            q = max(q, pri[j] + r[i - j] - 2);
        r[i] = q;
    }

    cout << r[l] << "\n";

    system("pause");
    return 0;
}
/*
10
1 2
2 4
3 6
4 7
5 11
6 9
7 8
8 12
9 8
10 12
0 0
*/
