#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEcho(string str)
{
    string get = str;
    reverse(str.begin(), str.end());
    return str == get;
}

int main()
{
    string str;
    cin >> str;

    vector<string> dic;
    for (int i = 0; i <= str.length() - 3; i++)
    {
        for (int j = 3; j <= str.length() - i; j++)
        {
            dic.push_back(str.substr(i, j));
        }
    }
    // for (auto i : dic)
    //    cout << i << "\n";

    string ans;
    for (auto &i : dic)
        ans = isEcho(i) && i.length() > ans.length() ? i : ans;

    cout << ans << "\n";

    system("pause");
    return 0;
}