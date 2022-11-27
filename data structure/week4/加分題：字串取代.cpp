#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str, a, b;

    getline(cin, str);
    //cout << *(str.end() - 1);
    if (str.back() == '\r')
        str.erase(str.end() - 1);
    getline(cin, a);
    if (a.back() == '\r')
        a.erase(a.end() - 1);
    getline(cin, b);
    if (b.back() == '\r')
        b.erase(b.end() - 1);

    while (str.find(a) != string::npos)
    {
        str.replace(str.find(a), a.length(), b);
        //cout << str << "\n";
    }

    cout << str << "\n";

    system("pause");
    return 0;
}
