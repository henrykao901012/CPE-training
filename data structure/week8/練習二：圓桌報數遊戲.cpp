#include <iostream>

using namespace std;

class chain
{
public:
    int num;
    chain *p;
    void insert(chain *&, int, int);
    void del(chain *&, int);
    void print(chain *);
    int at(chain *, int);

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

void chain::del(chain *&start, int pos)
{
    if (pos < 0 || pos >= count)
        throw POS_ERROR;
    if (!pos)
    {
        chain *ready_to_del = start;
        start = start->p;
        delete ready_to_del;
        count--;
        return;
    }
    del(start->p, pos - 1);
}

void chain::print(chain *start)
{
    cout << "Created Linked list is:";
    while (start)
    {
        cout << "  " << start->num;
        start = start->p;
    }
    cout << " \n";
}

int chain::at(chain *start, int pos)
{
    if (pos < 0 || pos >= count)
        throw POS_ERROR;
    while (pos--)
        start = start->p;
    return start->num;
}

int main()
{
    //cout << "here1\n";
    int n, a, b;
    cin >> n >> a >> b;
    //cout << "here2\n";
    //cout << n << " " << a << " " << b << "\n";
    chain chain_lib, *start = 0;
    for (int i = 1; i <= n; i++)
        chain_lib.insert(start, chain::count, i);
    //chain_lib.print(start);
    //for (int i = 1; i <= n; i++)
    //    cout << chain_lib.at(start, i - 1);

    int pos = a + b - 2; // ( a - 1 ) + ( b - 1 )
    while (1)
    {
        cout << chain_lib.at(start, pos) << " \n"[chain::count == 1];
        chain_lib.del(start, pos);
        if (chain::count == 0)
            break;
        pos = (pos + b - 1) % chain::count;
    }

    system("pause");
    return 0;
}
