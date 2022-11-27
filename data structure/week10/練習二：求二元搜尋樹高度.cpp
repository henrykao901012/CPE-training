#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> a(100, 0);
    int n;
    while (cin >> n)
    {
        //cout << log2(3) << "\n";
        if (!a[0])
        {
            a[0] = n;
            continue;
        }

        for (int i = 0; i < a.size(); i++)
            if (n < a[i] && a[i] && !a[i * 2 + 1])
            {
                a[i * 2 + 1] = n;
                break;
            }
            else if (n > a[i] && a[i] && !a[i * 2 + 2])
            {
                a[i * 2 + 2] = n;
                break;
            }
        //for (auto i : a)
        //    cout << i << " ";
    }

    int pos = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        if (!a[i])
            pos++;
        else
            break;
    cout << ceil(log2(a.size() - pos)) << "\n";

    system("pause");
    return 0;
}