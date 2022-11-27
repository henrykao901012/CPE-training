#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> initial_train;
    for (int i = 1; i <= n; i++)
        initial_train.push_back(i);

    int first;
    while (cin >> first && first != -1)
    {
        vector<int> get_train;
        vector<int> train = initial_train;
        stack<int> buf;
        get_train.push_back(first);
        for (int i = 0; i < n - 1; i++)
        {
            int get;
            cin >> get;
            get_train.push_back(get);
        }

        try
        {
            for (auto i : get_train)
            {
                if (find(train.begin(), train.end(), i) == train.end())
                {
                    if (i != buf.top())
                        throw "NO";
                    buf.pop();
                }
                else
                {
                    for (int j = 0; j < train.size(); j++)
                    {
                        if (train[j] == i)
                        {
                            train[j] = 0;
                            break;
                        }
                        if (train[j])
                        {
                            buf.push(train[j]);
                            train[j] = 0;
                        }
                    }
                }
            }
            throw "YES";
        }
        catch (const char *str)
        {
            cout << str << "\n";
        }
    }

    system("pause");
    return 0;
}