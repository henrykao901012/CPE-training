#include <iostream>

using namespace std;
int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        int sum = 0;
        for (auto i : t)
        {
            if (i == s[sum])
                sum++;
        }
        if (sum == s.length())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    system("pause");
    return 0;
}
