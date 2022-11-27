#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<char, int> m;
    char c;
    while (cin >> c && c != 'l')
    {
        if (m.find(c) == m.end())
            m[c] = 1;
        else
            m[c]++;
    }
    char in_out[2], f = 0;
    for (auto i : m)
        if (i.second == 1)
            in_out[f++] = i.first;

    f < 2 ? cout << "null\n" : cout << in_out[0] << " " << in_out[1] << "\n";
    system("pause");
    return 0;
}