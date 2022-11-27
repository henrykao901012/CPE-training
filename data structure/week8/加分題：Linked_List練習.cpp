#include "bits/stdc++.h"

using namespace std;

bool str_cmp(string a, string b)
{
    if (a.size() != b.size())
        return 0;
    bool ans = 1;
    for (int i = 0; i < a.size(); i++)
        ans &= a[i] == b[i] || abs(a[i] - b[i]) == 'a' - 'A';
    return ans;
}

void str_insert(pair<vector<string>, vector<int>> &dic, string s, int pos)
{
    int len = dic.first.size();
    for (int i = 0; i < len; i++)
    {
        if (str_cmp(s, dic.first[i]))
        {
            dic.second[i]++;
            return;
        }
    }
    if (pos > len)
        return;
    dic.first.insert(dic.first.begin() + pos, s);
    dic.second.insert(dic.second.begin() + pos, 1);
}

int main()
{
    pair<vector<string>, vector<int>> dic;
    string s;
    while (cin >> s && s != "#Finish")
        str_insert(dic, s, dic.first.size());

    while (cin >> s && s[1] != 'E')
    {
        string tok;
        int pos;
        switch (s[1])
        {
        case 'I':
            cin >> pos >> tok;
            str_insert(dic, tok, pos);
            break;
        case 'A':
            cin >> tok;
            str_insert(dic, tok, dic.first.size());
            break;
        case 'P':
            for (int i = 0; i < dic.first.size(); i++)
                cout << dic.first[i] << ", " << dic.second[i] << "\n";
            break;
        }
    }

    system("pause");
    return 0;
}
