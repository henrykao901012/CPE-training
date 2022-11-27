#include <iostream>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

void operator_initial(map<char, int> &dic)
{
    dic['('] = 0;
    dic[')'] = 3;
    dic['+'] = dic['-'] = 1;
    dic['*'] = dic['/'] = dic['%'] = 2;
    dic['#'] = -1;
}

int main()
{
    map<char, int> dic;
    operator_initial(dic);
    // for (auto i : dic)
    //    cout << int(i.first) << " " << i.first << " " << i.second.first << " " << i.second.second << "\n";
    int count;
    cin >> count;
    //if (getchar() == '\r')
    //    getchar();
    cin.ignore();
    cin.ignore();
    while (count--)
    {
        string get_whole_line;
        getline(cin, get_whole_line);
        stringstream buf_in(get_whole_line + "#");
        stringstream buf_out;
        stack<char> box;
        char s;
        while (buf_in >> s)
        {
            if (s >= '0' && s <= '9')
                buf_out << s << " ";
            else
            {
                if (s == '(')
                    box.push(s);
                else if (s == ')')
                {
                    while (box.top() != '(')
                    {
                        buf_out << box.top() << " ";
                        box.pop();
                    }
                    box.pop();
                }
                else
                {
                    if (box.empty() || dic[s] > dic[box.top()])
                        box.push(s);
                    else
                    {
                        while (!box.empty() && dic[s] <= dic[box.top()])
                        {
                            buf_out << box.top() << " ";
                            box.pop();
                        }
                        box.push(s);
                    }
                }
            }
        }
        cout << buf_out.str().substr(0, buf_out.str().size() - 1) << "\n";
    }

    system("pause");
    return 0;
}