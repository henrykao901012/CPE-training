#include <bits/stdc++.h>

using namespace std;

class chain
{
public:
    int num;
    chain *p;

    static void insert(chain *&, int, int);
    static void print(chain *);
    static void reverse(chain *&);

    inline static int count = 0;
    inline static const string POS_ERROR = "Invalid position.";
};

void chain::insert(chain *&start, int pos, int n)
{
    if (pos < 0 || pos > count)
        throw POS_ERROR;
    if (!pos)
    {
        chain *created = new chain;
        created->num = n;
        created->p = start;
        start = created;
        count++;
        return;
    }
    insert(start->p, pos - 1, n);
}

void chain::print(chain *start)
{
    //cout << "Created Linked list is:";
    stringstream ans;
    while (start)
    {
        ans << start->num << " ";
        start = start->p;
    }
    cout << ans.str().substr(0, ans.str().size() - 1) << "\n";
}

void chain::reverse(chain *&start)
{
    chain *a = 0, *b;
    while (start)
    {
        b = a;
        a = start;
        start = start->p;
        a->p = b;
    }
    start = a;
}

int main()
{
    chain chain_lib, *start = 0;
    int a;
    while (cin >> a)
        chain::insert(start, chain::count, a);

    //chain_lib.print(start);
    chain::reverse(start);
    chain::print(start);

    system("pause");
    return 0;
}