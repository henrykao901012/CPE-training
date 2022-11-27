#include <bits/stdc++.h>
using namespace std;

int weight = 0;
int maxV = 0;

struct thing
{
    int n, w, v;
    thing(int n, int w, int v)
    {
        (*this).n = n;
        (*this).w = w;
        (*this).v = v;
    }
};

vector<thing> item, ans, tmp;

void dfs(int num, int tow, int tov)
{
    double preV = (double)tov;
    int preW = tow;

    if (num == item.size())
    {
        return;
    }
    for (int i = num; i < item.size(); i++)
    {
        if (preW + item[i].w > weight)
        {
            preV += (weight - preW) * item[i].v / item[i].w;
            break;
        }
        else
        {
            preW += item[i].w;
            preV += item[i].v;
        }
    }

    if (preV <= maxV)
    {
        return;
    }
    if (tow + item[num].w <= weight)
    {
        tmp.push_back(item[num]);

        if (tov + item[num].v > maxV)
        {
            maxV = tov + item[num].v;
            ans = tmp;
        }

        dfs(num + 1, tow + item[num].w, tov + item[num].v);
        tmp.pop_back();
    }
    dfs(num + 1, tow, tov);
}

bool cmp(thing x, thing y)
{
    return x.v * y.w > y.v * x.w;
}

int main()
{
    int nu, we, va;

    cin >> weight;
    cin >> nu >> we >> va;
    while (nu != -1 && we != -1 && va != -1)
    {
        item.push_back(thing(nu, we, va));
        cin >> nu >> we >> va;
    }

    sort(item.begin(), item.end(), cmp);

    dfs(0, 0, 0);
    for (auto i : ans)
    {
        cout << i.n << " ";
    }
    cout << endl;
    cout << maxV << endl;
}