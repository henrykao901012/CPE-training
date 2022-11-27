#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a[100][100] = {0}, m, n, max = 0;
    while (cin >> m >> n)
    {
        // cout << m << " " << n << "\n";
        max = m > max ? m : (n > max ? n : max);
        a[m][n] = a[n][m] = 1;
    }
    cout << "Adjacency matrix:\n";
    for (int i = 0; i <= max; i++)
        for (int j = 0; j <= max; j++)
            cout << a[i][j] << " \n"[j == max];

    cout << "\nAdjacency list:\n";
    for (int i = 0; i <= max; i++)
    {
        cout << i << ": ";
        for (int j = 0; j <= max; j++)
            if (a[i][j])
                cout << j << " -> ";
        cout << "end\n";
    }

    system("pause");
    return 0;
}