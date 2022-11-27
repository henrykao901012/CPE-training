#include <bits/stdc++.h>

using namespace std;
int stuff[8000][200] = {0}, c[8000][200];
int main()
{
    int size, n = 0, w[9000], v[9000], max;
    cin >> size;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        cin >> w[n] >> v[n];
        max = n;
    }

    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            if (j - w[i] < 0)
                c[i + 1][j] = c[i][j];
            else
            {
                c[i + 1][j] = std::max(c[i][j - w[i]] + v[i], c[i][j]);
                if (c[i][j - w[i]] + v[i] > c[i][j])
                    stuff[i][j] = 1;
            }
        }
    }
    for (int i = max, j = size; i >= 0; i--)
    {
        if (stuff[i][j])
        {
            cout << i << " ";
            j -= w[i];
        }
    }
    cout << endl
         << c[max][size] << endl;
    return 0;
}