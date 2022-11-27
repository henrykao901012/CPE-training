#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        if (isdigit(str.front()) && isdigit(str.back()))
        {
            cout << "same\n";
            continue;
        }

        bool is_pre = 0;
        if (isdigit(str.back()))
        {
            reverse(str.begin(), str.end());
            is_pre = 1;
        }

        stack<string> box;
        for (auto i : str)
        {
            if (isdigit(i))
            {
                string get;
                get += i;
                box.push(get);
            }
            else
            {
                string second = box.top();
                box.pop();
                string first = box.top();
                box.pop();
                box.push("(" + first + i + second + ")");
            }
        }

        string ans = box.top();
        if (is_pre)
        {
            reverse(ans.begin(), ans.end());
            for (auto &i : ans)
                i = i == '(' ? ')' : (i == ')' ? '(' : i);
        }
        cout << ans.substr(1, ans.size() - 2) << "\n";
    }
    system("pause");
    return 0;
}