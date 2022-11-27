#include <bits/stdc++.h>

using namespace std;
stringstream buf;
vector<int> init_train, get_train;

void clear_all_in_out_stream(string s, int len)
{
    buf.clear();
    buf.str("");
    buf << s;
    init_train.clear();
    get_train.clear();
    while (buf >> s)
        get_train.push_back(stoi(s));
    for (int i = 0; i < len; i++)
        init_train.push_back(i);
}

bool is_legal_train_queue(string s, int len)
{
    stack<int> box;
    clear_all_in_out_stream(s, len);

    for (int i = 0; i < len; i++)
    {
        if (init_train[get_train[i]] == -1)
        {
            if (box.top() != get_train[i])
                return 0;
            box.pop();
            if (!box.empty())
            {
                if (box.top() != get_train[i + 1])
                    return 0;
                box.pop();
                init_train[++i] = -1;
            }
        }
        else
        {
            for (int j = 0; j < get_train[i]; j++)
            {
                if (init_train[j] != -1)
                {
                    box.push(init_train[j]);
                    init_train[j] = -1;
                }
            }
            init_train[get_train[i]] = -1;
        }
    }
    return 1;
}

int main()
{
    string s;
    getline(cin, s);
    int len, count;
    buf << s;
    buf >> len >> count;
    //cout << len << " " << count << "\n";

    const string ans[] = {"impossible", "possible"};
    while (count--)
    {
        getline(cin, s);
        //cout << s << "\n";
        cout << ans[is_legal_train_queue(s, len)] << "\n";
    }

    system("pause");
    return 0;
}