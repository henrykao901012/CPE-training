#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        string str;
        if (a >= b)
            str = a > b ? ">" : "=";
        else
            str = "<";
        cout << str << "\n";
    }

    system("pause");
    return 0;
}
