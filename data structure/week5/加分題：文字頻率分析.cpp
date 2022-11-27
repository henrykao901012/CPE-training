#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{

    string prefix, suffix;
    int char_fre, word_fre;
    cin >> prefix >> suffix >> char_fre >> word_fre;

    map<string, int> dic;
    string get;
    while (cin >> get && get != "ggg")
    {
        if (dic.find(get) == dic.end())
            dic[get] = 1;
        else
            dic[get]++;
    }

    cout << "prefix of " << prefix << ":\n";
    for (auto i : dic)
    {
        if (i.first.substr(0, prefix.length()) == prefix)
            cout << i.first << "\n";
    }

    cout << "suffix of " << suffix << ":\n";
    for (auto i : dic)
    {
        if (i.first.substr(i.first.length() - suffix.length(), suffix.length()) == suffix)
            cout << i.first << "\n";
    }

    cout << "character frequency over " << char_fre << ":\n";
    int count_fre[52] = {0};
    for (auto i : dic)
        for (auto j : i.first)
            count_fre[islower(j) ? j - 'a' : j - 'A' + 26] += i.second;
    for (int i = 0; i < 52; i++)
        if (count_fre[i] >= char_fre)
            printf("%c,%d\n", i < 26 ? i + 'a' : i - 26 + 'A', count_fre[i]);

    cout << "word frequency over " << word_fre << ":\n";
    for (auto i : dic)
        if (i.second >= word_fre)
            printf("%s,%d\n", i.first.c_str(), i.second);

    system("pause");
    return 0;
}
