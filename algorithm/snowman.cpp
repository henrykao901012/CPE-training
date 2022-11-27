#include <bits/stdc++.h>
#define N 100000

using namespace std;
long long int n, X[N], C[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> X[i];
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
        C[i] += i ? C[i - 1] : 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (X[i] > C[n - 1] - C[i - 1])
            cout << -1;
        else
        {
            for (int j = i; j < n; j++)
                if (X[i] <= C[j] - C[i - 1])
                {
                    cout << j + 1;
                    break;
                }
        }
        cout << " ";
    }
    cout << "\n";

    system("pause");
    return 0;
}