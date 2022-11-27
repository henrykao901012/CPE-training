#include <iostream>

using namespace std;
int main()
{
    string str;
    while (cin >> str && str != "0")
    {
        int ans = 0;
        for (auto i : str)
            ans = (ans * 10 + i - '0') % 17;

        cout << (ans == 0) << "\n";
    }

    system("pause");
    return 0;
}
