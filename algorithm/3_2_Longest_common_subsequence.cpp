#include <bits/stdc++.h>

using namespace std;

/*                                          TLE
int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + lcs(x, y, m - 1, n - 1);
    else
        return max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
}*/
int lcs(string x, string y)
{
    int m = x.size(), n = y.size();
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));
    // int L[m + 1][n + 1] = {0};    ??????

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << lcs(a, b) << "\n";

    system("pause");
    return 0;
}