#include <iostream>

using namespace std;
void reverse(string &str, int n)
{
    for (int j = 0; j < str.length(); j += n)
        for (int i = 0; i < n / 2; i++)
        {
            char t = str[i + j];
            str[i + j] = str[j + n - 1 - i];
            str[j + n - 1 - i] = t;
        }
}
int main()
{

    int n;
    while (cin >> n && n)
    {
        string str;
        cin >> str;
        reverse(str, str.length() / n);
        cout << str << "\n";
    }

    system("pause");
    return 0;
}
