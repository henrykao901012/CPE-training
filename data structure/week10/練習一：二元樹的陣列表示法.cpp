#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> a(100, 0);
    int n, b[3];
    cin >> n;
    while (cin >> b[0] && b[0] != -1)
    {
        cin >> b[1] >> b[2];
        if (find(a.begin(), a.end(), b[0]) == a.end())
        {
            a[0] = b[0];
            a[1] = b[1];
            a[2] = b[2];
        }
        else
        {
            int pos = find(a.begin(), a.end(), b[0]) - a.begin();
            //cout << pos << "\n";
            if (b[1])
                a[pos * 2 + 1] = b[1];
            if (b[2])
                a[pos * 2 + 2] = b[2];
        }
    }

    int pos = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        if (!a[i])
            pos++;
        else
            break;
    for (int i = 0; i < a.size() - pos; i++)
        cout << a[i] << " \n"[i == a.size() - 1 - pos];

    system("pause");
    return 0;
}