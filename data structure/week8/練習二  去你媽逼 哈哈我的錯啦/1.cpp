#include "bits/stdc++.h"

using namespace std;
int main()
{
    vector<int> v;
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    int pos = a + b - 2;
    while (1)
    {
        cout << v[pos] << " \n"[v.size() == 1];
        v.erase(v.begin() + pos);
        if (v.empty())
            break;
        pos = (pos + b - 1) % v.size();
    }

    system("pause");
    return 0;
}
