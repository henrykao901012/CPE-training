#include <bits/stdc++.h>

using namespace std;
int main()
{
    int count;
    cin >> count;
    while (count--)
    {
        int d, n, tree[100000] = {0};
        cin >> d >> n;
        int i;
        while (n--)
            for (i = 1; i * 2 < 2 << (d - 1); i = tree[i] ? i * 2 : i * 2 + 1)
                tree[i] = !tree[i];
        cout << i << "\n";
    }
    cin >> count;
    system("pause");
    return 0;
}