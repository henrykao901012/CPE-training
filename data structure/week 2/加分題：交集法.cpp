#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int s;
    cin >> s;
    int get, sum = 0;
    vector<int> get_num;
    while (cin >> get)
    {
        get_num.push_back(get);
        sum += get;
    }

    vector<bool> init;
    for (int i = 0; i < get_num.size(); i++)
    {
        for (int j = 0; j < get_num[i]; j++)
            init.push_back(1);
        if (i != get_num.size() - 1)
            init.push_back(0);
    }
    /*
    for (auto i : ans)
        cout << i << " ";

    */
    vector<vector<bool>> dic;
    int left = s - sum - get_num.size() + 1;
    for (int i = 0; i < init.size(); i++)
    {
        vector<bool> ans = init;
        if (!init[i])
        {
            for (int j = 0; j < left; j++)
                ans.insert(ans.begin() + i + j, 0);
            dic.push_back(ans);
        }
    }

    /*  for (int i = 0; i < dic.size(); i++)
    {
        for (int j = 0; j < dic[i].size(); j++)
            cout << dic[i][j] << " ";
        cout << "\n";
    }
    */
    vector<bool> ans;
    for (int i = 0; i < s; i++)
    {
        bool get = 1;
        for (int j = 0; j < dic.size(); j++)
            get *= dic[j][i];
        ans.push_back(get);
    }
    /*
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
*/
    for (int i = 0; i < ans.size(); i++)
    {
        (i >= 0 && i < left) || (i >= ans.size() - left) ? cout << 0 : cout << ans[i];
        i == ans.size() - 1 ? cout << "\n" : cout << " ";
    }
    system("pause");
    return 0;
}
