#include <bits/stdc++.h>

using namespace std;

string sub(string a, string b)
{
    if (a.size() < b.size())
        return a;
    if (a == b)
        return "0";
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
                break;
            if (a[i] < b[i])
                return a;
        }
    }

    string str_get_zero;
    for (int i = 0; i < a.size() - b.size(); i++)
        str_get_zero += "0";
    b = str_get_zero + b;
    //cout << a << " " << b << "\n";

    for (int i = 0; i < a.size(); i++)
        a[i] += '0' - b[i];
    for (int i = a.size() - 1; i >= 1; i--)
    {
        a[i - 1] -= a[i] < '0';
        a[i] += (a[i] < '0') * 10;
    }
    int pos = 0;
    for (auto i : a)
    {
        if (i - '0')
            break;
        pos++;
    }
    return a.substr(pos, a.size() - pos);
}

vector<string> divide_strings(string a, string b)
{
    if (b == "0")
        throw "divided by 0";

    string quo;
    for (int i = a.size() - b.size(); i >= 0; i--)
    {
        int count = 0;
        string str_now_sub = b;
        for (int j = 0; j < i; j++)
            str_now_sub += "0";
        while (a != sub(a, str_now_sub))
        {
            a = sub(a, str_now_sub);
            count++;
        }
        quo += count + '0';
    }
    return vector<string>{quo == "" ? "0" : (quo[0] == '0' && quo != "0" ? quo.substr(1, quo.size() - 1) : quo), a};
}

int main()
{
    string a, b;
    /*
    while (1)
    {
        cin >> a >> b;
        cout << sub(a, b) << "\n";
    }
    */

    while (1)
    {
        cin >> a >> b;
        vector<string> v = divide_strings(a, b);
        cout << v[0] << " " << v[1] << "\n";
    }

    system("pause");
    return 0;
}