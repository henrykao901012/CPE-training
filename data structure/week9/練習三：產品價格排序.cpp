#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<pair<string, vector<int>>> dic;
    int n;
    cin >> n;
    while (n--)
    {
        string name;
        int price;
        cin >> name >> price;

        bool done = 0;
        for (auto &i : dic)
        {
            if (i.first == name)
            {
                i.second.push_back(price);
                done = 1;
                break;
            }
        }
        if (!done)
            dic.push_back({name, {price}});
    }

    for (auto i : dic)
    {
        cout << i.first << ",";
        sort(i.second.begin(), i.second.end());
        for (auto j : i.second)
            cout << j << ",";
        cout << "\n";
    }

    system("pause");
    return 0;
}