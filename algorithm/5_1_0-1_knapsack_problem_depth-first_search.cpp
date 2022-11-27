#include <bits/stdc++.h>
using namespace std;

struct thing
{
    int number, weight, value;
    thing(int nu, int we, int va) : number(nu), weight(we), value(va)
    {
    }
};

int MAX = 0;
vector<thing> ans, vc;
vector<thing> pa;

bool cmp(thing a, thing b)
{
    return ((double)a.value / a.weight) > ((double)b.value / b.weight);
}

void dfs(int value, int weight, int idx)
{
    if (value > MAX)
    { //更新答案
        MAX = value;
        ans = pa;
    }
    if (idx >= vc.size() || weight <= 0)
    { //若取完了或是沒有空間時，則結束
        return;
    }
    double prevalue = value;
    int tmpwe = weight;
    for (int i = idx; i < vc.size() && tmpwe > 0; i++)
    {
        if (tmpwe >= vc[i].weight)
        {
            prevalue += vc[i].value;
            tmpwe -= vc[i].weight;
        }
        else
        {
            prevalue += ((double)vc[i].value / vc[i].weight) * tmpwe;
            tmpwe = 0;
        }
    }
    if (prevalue <= (double)MAX)
    { //預測價值小於等於現在的價值(再取下取也不會比現在的大)
        return;
    }
    if (vc[idx].weight > weight)
    { //若放不下只能不取
        dfs(value, weight, idx + 1);
    }
    else
    {
        pa.push_back(vc[idx]); //放得下，並且要取
        dfs(value + vc[idx].value, weight - vc[idx].weight, idx + 1);
        pa.pop_back(); //拿出來，換跑放得下，可是不取
        dfs(value, weight, idx + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int total_weight, number, weight, value;
    cin >> total_weight;
    while (cin >> number >> weight >> value)
    {
        if (number == -1 && weight == -1 && value == -1)
            break;
        vc.push_back(thing(number, weight, value));
    }
    sort(vc.begin(), vc.end(), cmp);
    dfs(0, total_weight, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].number << " ";
    }
    cout << endl;
    cout << MAX << endl;
    return 0;
}