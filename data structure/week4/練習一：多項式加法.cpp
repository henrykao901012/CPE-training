#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<double, int> pdi;

class poly
{
public:
    vector<pdi> num;
    void get_poly(int);
    void print_poly();
    void sort_poly(poly &);
    void add(poly &);
    void mutil(poly &);
};

void poly::get_poly(int n)
{
    while (n--)
    {
        double number;
        int pow;
        cin >> number >> pow;
        num.push_back({number, pow});
    }
}

void poly::print_poly()
{
    for (int i = 0; i < num.size(); i++)
    {
        string ch = num[i].first < 0 ? "-" : (i == 0 ? "" : "+");
        double fix = num[i].first < 0 ? -num[i].first : num[i].first;
        cout << ch;
        if (num[i].second == 0)
            printf("%.2f", fix);
        else if (num[i].second == 1)
            printf("%.2fx", fix);
        else
            printf("%.2fx^%d", fix, num[i].second);
        if (i == num.size() - 1)
            cout << "\n";
    }
}

bool cmp(pdi a, pdi b)
{
    return a.second > b.second;
}

void poly::sort_poly(poly &a)
{
    sort(a.num.begin(), a.num.end(), cmp);
}

void poly::add(poly &a)
{
    for (int i = 0; i < a.num.size(); i++)
    {
        bool done = 0;
        for (int j = 0; j < num.size(); j++)
        {
            if (a.num[i].second == num[j].second)
            {
                num[j].first += a.num[i].first;
                if (num[j].first == 0)
                    num.erase(num.begin() + j);
                done = 1;
                break;
            }
        }
        if (!done)
            num.push_back({a.num[i].first, a.num[i].second});
    }
    sort_poly(*this);
    //sort(num.begin(), num.end(), cmp);
}

int main()
{
    int n;
    poly p1, p2;
    cin >> n;
    p1.get_poly(n);
    cin >> n;
    p2.get_poly(n);

    /* 
    p1.print_poly();
    p2.print_poly();
    poly p_test = p1;
    p_test.print_poly();
    */
    p1.print_poly();
    p2.print_poly();
    p1.add(p2);
    p1.print_poly();

    system("pause");
    return 0;
}
