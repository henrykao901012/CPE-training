#include <iostream>

using namespace std;

int num[100][100];

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void get_matric(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            num[i][j] = i * n + j + 1;
}

void print_matric(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << num[i][j];
            j == n - 1 ? cout << "\n" : cout << " ";
        }
    }
}

void horizonal(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
            swap(num[i][j], num[i][n - j - 1]);
    }
}

void vertical(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
            swap(num[j][i], num[n - j - 1][i]);
    }
}

void transport(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i > j)
                swap(num[i][j], num[j][i]);
    }
}

int main()
{
    int n;
    cin >> n;
    get_matric(n);
    //print_matric(n);

    string str;
    cin >> str;
    for (auto i : str)
    {
        switch (i)
        {
        case 'H':
            horizonal(n);
            break;
        case 'V':
            vertical(n);
            break;
        case 'D':
            transport(n);
        }
    }
    print_matric(n);

    system("pause");
    return 0;
}
