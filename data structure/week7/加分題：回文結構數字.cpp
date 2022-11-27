#include <iostream>
#include <algorithm>

using namespace std;

string my_reverse(string a)
{
    reverse(a.begin(), a.end());
    return a;
}

bool isEcho(int a)
{
    return my_reverse(to_string(a)) == to_string(a);
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
        if (isEcho(i))
            cout << i << " ";
    cout << "\n";

    system("pause");
    return 0;
}