#include <bits/stdc++.h>

using namespace std;

stringstream buf;
vector<int> pre, in;
vector<vector<int>> ans;

void get_data(vector<int> &v)
{
    string get;
    getline(cin, get);
    buf.clear();
    buf << get;
    while (buf >> get)
        v.push_back(stoi(get));
}

void tree_traversal(int pre_start, int pre_end, int in_start, int in_end, int deep)
{
    if (pre_start > pre_end || in_start > in_end || !pre[pre_start])
        return;
    ans[deep].push_back(pre[pre_start]);
    for (int i = in_start; i <= in_end; i++)
    {
        if (in[i] == pre[pre_start])
        {
            tree_traversal(pre_start + 1, pre_start + i - in_start, in_start, i - 1, deep + 1);
            tree_traversal(pre_start + i - in_start + 1, pre_end, i + 1, in_end, deep + 1);
        }
    }
}

int main()
{
    get_data(pre);
    get_data(in);

    ans.resize(pre.size());

    tree_traversal(0, pre.size(), 0, in.size(), 0);

    int count = 1;
    for (auto i : ans)
    {
        if (i.empty())
            continue;
        cout << count << ":";
        for (int j = 0; j < i.size(); j++)
            cout << i[j] << ",\n"[j == i.size() - 1];
        count++;
    }

    system("pause");
    return 0;
}