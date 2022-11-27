#include <iostream>
#include <map>

using namespace std;
int main()
{
    int n, sep[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sep[i];

    for (int i = 0; i < n; i++)
    {
        map<string, int> dic;
        while (sep[i]--)
        {
            string str;
            cin >> str;
            if (dic.find(str) == dic.end())
                dic[str] = 1;
            else
                dic[str]++;
        }
        int not_in_pair_count = 0;
        for (auto i : dic)
            not_in_pair_count += i.second % 2;
        cout << not_in_pair_count << "\n";
    }

    system("pause");
    return 0;
}