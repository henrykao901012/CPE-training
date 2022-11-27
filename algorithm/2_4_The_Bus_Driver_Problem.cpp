#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, d, r;
    while (cin >> n >> d >> r && n)
    {
        int mor[100] = {0}, eve[100] = {0};
        for (int i = 0; i < n; i++)
            cin >> mor[i];
        for (int i = 0; i < n; i++)
            cin >> eve[i];

        sort(mor, mor + 100, greater<int>());
        sort(eve, eve + 100, greater<int>());
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += mor[i] + eve[n - i - 1] > d ? (mor[i] + eve[n - i - 1] - d) * r : 0;

        cout << sum << "\n";
    }

    system("pause");
    return 0;
}