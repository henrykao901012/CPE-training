#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream buf(s);

    int a[1000] = {0}, size = 0;
    while (buf >> a[++size])
    {
        for (int i = size; i >= 2; i /= 2)
            if (a[i] < a[i / 2])
                swap(a[i], a[i / 2]);

        for (int i = 1; i <= size; i++)
            cout << "[" << i << "]" << a[i] << " \n"[i == size];
    }

    system("pause");
    return 0;
}