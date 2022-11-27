#include <iostream>
#include <sstream>
#include <stack>
#include <regex>
#include <string>

using namespace std;
int main()
{
    string str;
    getline(cin, str);

    stringstream buf_in(str);
    string s;
    stack<int> box;
    regex re("\\d+");
    while (buf_in >> s)
    {
        if (regex_match(s, re))
            box.push(stoi(s));
        else
        {
            int second = box.top();
            box.pop();
            int first = box.top();
            box.pop();
            switch (s[0])
            {
            case '+':
                box.push(first + second);
                break;
            case '-':
                box.push(first - second);
                break;
            case '*':
                box.push(first * second);
                break;
            case '/':
                box.push(first / second);
                break;
            case '%':
                box.push(first % second);
                break;
            }
        }
    }
    cout << box.top() << "\n";

    system("pause");
    return 0;
}