#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

class chain
{
public:
    pii num;
    chain *p;

    void insert(chain *&, int, pii);
    void insert(chain *&, pii);

    void del(chain *&, int);
    void print(chain *);
    pii at(chain *, int);

    chain *add(chain *, chain *);
    chain *muti(chain *, chain *);

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

void chain::insert(chain *&start, int pos, pii n)
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
    stringstream ans;
    while (start)
    {
        int num = start->num.first, pow = start->num.second;
        ans << num << (pow > 0 ? "x" : "") << (pow > 1 ? "^" + to_string(pow) : "") << " + ";
        start = start->p;
    }
    cout << ans.str().substr(0, ans.str().size() - 3) << "\n";
}

pii chain::at(chain *start, int pos)
{
    if (pos < 0 || pos >= size(start))
        throw POS_ERROR;
    while (pos--)
        start = start->p;
    return start->num;
}

void chain::insert(chain *&start, pii n)
{
    for (int i = 0; i < size(start); i++)
    {
        if (at(start, i).second == n.second)
        {
            chain *it = start;
            for (int j = 0; j < i; j++)
                it = it->p;
            it->num.first += n.first;
            return;
        }
        else if (at(start, i).second < n.second)
        {
            insert(start, i, n);
            return;
        }
    }
    insert(start, size(start), n);
}

chain *chain::add(chain *a, chain *b)
{
    chain *ans = 0;
    for (int i = 0; i < size(a); i++)
        insert(ans, at(a, i));
    for (int i = 0; i < size(b); i++)
        insert(ans, at(b, i));
    return ans;
}

chain *chain::muti(chain *a, chain *b)
{
    chain *ans = 0;
    for (int i = 0; i < size(b); i++)
    {
        chain *get = 0;
        for (int j = 0; j < size(a); j++)
        {
            //cout << at(b, i).first << " " << at(a, j).first << " " << at(b, i).second << " " << at(a, j).second << "\n";
            insert(get, {at(b, i).first * at(a, j).first, at(b, i).second + at(a, j).second});
            //print(get);
        }

        ans = add(ans, get);
    }
    return ans;
}

int main()
{
    chain chain_lib, *one = 0, *two = 0;

    int num, pow;
    while (cin >> num && num != -1)
    {
        cin >> pow;
        chain_lib.insert(one, {num, pow});
    }

    while (cin >> num && num != -1)
    {
        cin >> pow;
        chain_lib.insert(two, {num, pow});
    }

    //chain_lib.print(one);
    //chain_lib.print(two);

    chain *three = chain_lib.add(one, two);
    cout << "add = ";
    chain_lib.print(three);

    chain *four = chain_lib.muti(one, two);
    cout << "mult = ";
    chain_lib.print(four);

    system("pause");
    return 0;
}
