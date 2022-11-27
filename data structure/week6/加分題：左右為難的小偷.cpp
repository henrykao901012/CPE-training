#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class stolen
{
public:
    string name;
    double value, weight;
    inline static double total_weight = 0;
    inline static double total_value = 0;
};

int main()
{
    vector<stolen> beg;
    string get;
    while (cin >> get && get != "ggg")
    {
        double v, w;
        cin >> v >> w;
        if (stolen::total_weight + w <= 20)
        {
            beg.push_back({get, v, w});
            stolen::total_weight += w;
            stolen::total_value += v;
            continue;
        }

        for (int i = beg.size() - 1; i >= 0; i--)
        {
            if (v > beg[i].value && stolen::total_weight - beg[i].weight + w <= 20)
            {
                //cout << beg[i].name << " " << beg[i].value << " " << beg[i].weight << " be erase!!\n";
                stolen::total_weight += w - beg[i].weight;
                stolen::total_value += v - beg[i].value;
                beg.erase(beg.begin() + i);
                stolen ans = {get, v, w};
                beg.insert(beg.end(), ans);
                //cout << "now weight = " << stolen::total_weight << "\n";
                break;
            }
        }
    }
    reverse(beg.begin(), beg.end());
    for (auto &i : beg)
        printf("%s %.1f %.1f\n", i.name.c_str(), i.value, i.weight);

    printf("weight:%.1f\nvalue:%.1f\n", stolen::total_weight, stolen::total_value);

    system("pause");
    return 0;
}