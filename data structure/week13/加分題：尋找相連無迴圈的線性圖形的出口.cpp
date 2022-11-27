#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<string> start, end;
    string a, b;
    while (cin >> a >> b)
    {
        start.push_back(a);
        end.push_back(b);
    }

    for (int i = start.size() - 1; i >= 0; i--)
    {
        auto get = find(end.begin(), end.end(), start[i]);
        if (get != end.end())
        {
            end.erase(get);
            start.erase(start.begin() + i);
        }
    }

    cout << (start.size() != 1 ? "null" : start.front() + " " + end.front()) << "\n";

    system("pause");
    return 0;
}