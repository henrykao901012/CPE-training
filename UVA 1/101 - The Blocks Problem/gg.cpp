#include <bits/stdc++.h>

using namespace std;
int n;
vector<stack<int>> v(25);

int find(int a)
{
    for (int i = 0; i < n; i++)
    {
        stack<int> copy = v[i];
        while (!copy.empty())
        {
            if (copy.top() == a)
                return i;
            copy.pop();
        }
    }
    return -1;
}

void return_back(int a) //  returning all the blocks above a
{
    int pos = find(a);
    while (v[pos].top() != a)
    {
        v[v[pos].top()].push(v[pos].top());
        v[pos].pop();
    }
}

void move_onto(int a, int b)
{
    return_back(a);
    return_back(b);
    v[find(a)].pop();
    v[find(b)].push(a);
}

void move_over(int a, int b)
{
    return_back(a);
    v[find(a)].pop();
    v[find(b)].push(a);
}

void pile_over(int a, int b)
{
    int fa = find(a), fb = find(b);
    stack<int> get;
    while (v[fa].top() != a)
    {
        get.push(v[fa].top());
        v[fa].pop();
    }
    get.push(a);
    v[fa].pop();
    while (!get.empty())
    {
        v[fb].push(get.top());
        get.pop();
    }
}

void pile_onto(int a, int b)
{
    return_back(b);
    pile_over(a, b);
}

void stack_print()
{
    int count = 0;
    for (auto box : v)
    {
        if (count == n)
            break;
        cout << count++ << ":";
        stack<int> copy;
        while (!box.empty())
        {
            copy.push(box.top());
            box.pop();
        }
        while (!copy.empty())
        {
            cout << " " << copy.top();
            copy.pop();
        }
        cout << "\n";
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        v[i].push(i);
    string act, dis;
    int a, b;
    while (cin >> act && act[0] != 'q' && cin >> a >> dis >> b)
    {
        // int fa = find(a), fb = find(b);
        if (find(a) == find(b))
            continue;
        if (act[0] == 'm')
        {
            if (dis[1] == 'n')
                move_onto(a, b);
            else
                move_over(a, b);
        }
        else
        {
            if (dis[1] == 'n')
                pile_onto(a, b);
            else
                pile_over(a, b);
        }
    }

    stack_print();

    system("pause");
    return 0;
}