#include <bits/stdc++.h>

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
    void reverse(chain *&);

    int size(chain *);
    inline static const string POS_ERROR = "Invalid position.";
};

int chain::size(chain *start)
{
    int count = 0;
    while (start)
    {
        start = start->p;
        count++;
    }
    return count;
}

void chain::insert(chain *&start, int pos, int n)
{
    if (pos < 0 || pos > size(start))
        throw POS_ERROR;
    if (!pos)
    {
        chain *created = new chain;
        created->num = n;
        created->p = start;
        start = created;
        return;
    }
    insert(start->p, pos - 1, n);
}

void chain::del(chain *&start, int pos)
{
    if (pos < 0 || pos >= size(start))
        throw POS_ERROR;
    if (!pos)
    {
        chain *ready_to_del = start;
        start = start->p;
        delete ready_to_del;
        return;
    }
    del(start->p, pos - 1);
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

int chain::at(chain *start, int pos)
{
    if (pos < 0 || pos >= size(start))
        throw POS_ERROR;
    while (pos--)
        start = start->p;
    return start->num;
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
    chain chain_lib;
    int n;
    cin >> n;
    while (n--)
    {
        chain *start = 0;
        //chain::count = 0;
        const vector<char> dic = {'f', 'i', 'a', 'd'};
        char get;
        while (cin >> get && find(dic.begin(), dic.end(), get) != dic.end())
        {
            try
            {
                int pos, num;
                switch (get)
                {
                case 'f':
                    cin >> num;
                    chain_lib.insert(start, 0, num);
                    break;
                case 'i':
                    cin >> num >> pos;
                    chain_lib.insert(start, pos, num);
                    break;
                case 'a':
                    cin >> num;
                    chain_lib.insert(start, chain_lib.size(start), num);
                    break;
                    /*  case 'd':
                    cin >> pos;
                    chain_lib.del(start, pos);
                    break;      */
                }
            }
            catch (const string &str)
            {
                cout << str << "\n";
            }
            chain_lib.print(start);
        }
        cout << (n ? "\n" : "");
    }

    system("pause");
    return 0;
}