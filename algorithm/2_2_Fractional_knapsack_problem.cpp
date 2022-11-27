#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

bool cmp(pii a, pii b)
{
    return (double)a.first / a.second > (double)b.first / b.second;
}
int main()
{
    vector<pii> bag;
    int s, v, w;
    cin >> s;
    while (cin >> v >> w)
        bag.push_back({v, w});

    sort(bag.begin(), bag.end(), cmp);

    // for (auto i : bag)
    //   cout << i.first << " " << i.second << " " << (double)i.first / i.second << "\n";

    int c = 0;
    double sum = 0;
    for (int i = 0; i < bag.size(); i++)
    {
        if (c + bag[i].second <= s)
        {
            c += bag[i].second;
            sum += bag[i].first;
        }
        else
        {
            sum += (s - c) * (double)bag[i].first / bag[i].second;
            break;
        }
    }

    printf("%6f\n", sum);

    system("pause");
    return 0;
}

/*
18
45 7
40 6
51 85
57 10
17 43
35 84
*/