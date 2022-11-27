#include "bits/stdc++.h"

using namespace std;

class stolen
{
public:
    string name;
    int value;
    double weight;
    inline static double total_weight = 0;
    inline static int total_value = 0;
};

bool cmp(stolen a, stolen b)
{
    return a.value * b.weight == b.value * a.weight ? a.weight > b.weight : a.value * b.weight < b.value * a.weight;
}

int main()
{
    vector<stolen> beg;
    string get_name;
    while (cin >> get_name && get_name != "-1")
    {
        int v;
        double w;
        cin >> v >> w;

        if (stolen::total_weight + w <= 20)
        {
            beg.push_back({get_name, v, w});
            stolen::total_weight += w;
            stolen::total_value += v;
            sort(beg.begin(), beg.end(), cmp);
            continue;
        }

        reverse(beg.begin(), beg.end());
        for (int i = beg.size() - 1; i >= 0; i--)
        {
            if (v * beg[i].weight > beg[i].value * w)
            {
                stolen::total_value -= beg[i].value;
                stolen::total_weight -= beg[i].weight;
                beg.pop_back();
                if (stolen::total_weight + w <= 20)
                {
                    stolen::total_value += v;
                    stolen::total_weight += w;
                    beg.push_back({get_name, v, w});
                    //beg.insert(beg.begin() + i, {get_name, v, w});
                    //beg.erase(beg.begin() + i + 1);
                    break;
                }
            }
        }
        reverse(beg.begin(), beg.end());
    }
    for (int i = 0; i < beg.size(); i++)
        cout << beg[i].name << " \n"[i == beg.size() - 1];
    printf("total weight:%.2f\ntotal value:%d\n", stolen::total_weight, stolen::total_value);

    system("pause");
    return 0;
}