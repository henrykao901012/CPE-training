#include <bits/stdc++.h>

using namespace std;
int main()
{
    string get, s;
    getline(cin, get);
    while (getline(cin, s) && s != "ggg")
        while (get.find(s[0]) != string::npos)
            get[get.find(s[0])] = s[4];

    //cout << get << "\n";
    stringstream buf(get);
    stack<int> box;
    char ch;
    while (buf >> ch)
    {
        //cout << ch << "\n";
        if (ch != '(' && ch != ')')
        {
            box.push(ch);
            continue;
        }

        if (ch == ')')
        {
            int second = box.top() - '0';
            box.pop();
            int first = box.top() - '0';
            box.pop();
            char op = box.top();
            box.pop();
            //cout << "first = " << first << "  second = " << second << "  op = " << op << "\n";
            switch (op)
            {
            case '+':
                box.push(first + second + '0');
                break;
            case '-':
                box.push(first - second + '0');
                break;
            case '*':
                box.push(first * second + '0');
                break;
            case '/':
                box.push(first / second + '0');
                break;
            }
        }
    }

    cout << box.top() - '0' << "\n";

    system("pause");
    return 0;
}