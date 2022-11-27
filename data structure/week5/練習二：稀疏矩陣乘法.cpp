//  A * A^T
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class sparse_matrix
{
public:
    int ud, rl, num;
};

class sparse_matrix_list
{
public:
    int m, n, count;
    vector<sparse_matrix> mylist;
    void get_sparse_matrix(int);
    void print_sparse_matrix();

    sparse_matrix_list matrix_multi_matric_transport();
};

void sparse_matrix_list::get_sparse_matrix(int count)
{
    this->count = count;
    int max = numeric_limits<int>::min();
    while (count--)
    {
        string str;
        cin >> str;
        int num = str[6] == '-' ? -str[7] + '0' : str[6] - '0';
        sparse_matrix get = {str[1] - '0' - 1, str[3] - '0' - 1, num};
        mylist.push_back(get);
        max = str[1] - '0' > max ? str[1] - '0' : max;
    }
    this->m = max, this->n = max;
}

void sparse_matrix_list::print_sparse_matrix()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool done = 0;
            for (auto k : mylist)
            {
                if (k.ud == i && k.rl == j)
                {
                    cout << k.num;
                    done = 1;
                    break;
                }
            }
            if (!done)
                cout << "0";
            j == n - 1 ? cout << "\n" : cout << " ";
        }
    }
}

sparse_matrix_list sparse_matrix_list::matrix_multi_matric_transport()
{
    sparse_matrix_list ans;
    ans.m = m, ans.n = n;
    for (auto i : mylist)
    {
        for (auto j : mylist)
        {
            if (i.rl == j.rl)
            {
                bool done = 0;
                //cout << i.ud << " " << j.ud << " " << i.num * j.num << " ";
                for (auto &k : ans.mylist)
                    if (k.ud == i.ud && k.rl == j.ud)
                    {
                        k.num += i.num * j.num;
                        done = 1;
                        break;
                    }
                //cout << "done = " << done << "\n";
                if (!done)
                {
                    sparse_matrix get = {i.ud, j.ud, i.num * j.num};
                    ans.mylist.push_back(get);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int count;
    cin >> count;

    sparse_matrix_list a;
    a.get_sparse_matrix(count);
    //a.print_sparse_matrix();

    a.matrix_multi_matric_transport().print_sparse_matrix();

    system("pause");
    return 0;
}
