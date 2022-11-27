#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class sparse_matrix
{
public:
    int ud, rl, num;
    void swap()
    {
        int t = ud;
        ud = rl;
        rl = t;
    }
};

class sparse_matrix_list
{
public:
    int m, n, count;
    vector<sparse_matrix> mylist;
    void get_sparse_matrix(int, int, int);
    void print_sparse_matrix();

    static bool cmp(sparse_matrix, sparse_matrix);
    void transport();
};

void sparse_matrix_list::get_sparse_matrix(int m, int n, int count)
{
    this->m = m, this->n = n, this->count = count;
    while (count--)
    {
        int ud, rl, num;
        cin >> ud >> rl >> num;
        sparse_matrix get = {ud, rl, num};
        mylist.push_back(get);
    }
}

void sparse_matrix_list::print_sparse_matrix()
{
    cout << m << " " << n << " " << count << "\n";
    for (auto i : mylist)
        cout << i.ud << " " << i.rl << " " << i.num << "\n";
}

bool sparse_matrix_list::cmp(sparse_matrix a, sparse_matrix b)
{
    if (a.rl == b.rl)
        return a.ud < b.ud;
    return a.rl < b.rl;
}

void sparse_matrix_list::transport()
{
    sort(mylist.begin(), mylist.end(), cmp);
    for (auto &i : mylist)
        i.swap();
}

int main()
{
    int m, n, count;
    cin >> m >> n >> count;

    sparse_matrix_list a;
    a.get_sparse_matrix(m, n, count);
    //a.print_sparse_matrix();

    a.transport();
    a.print_sparse_matrix();

    system("pause");
    return 0;
}
