#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stringstream buf(s);

    int a[100] = {0}, size = 0;
    while (buf >> a[++size])
    {
        for (int i = size; i >= 2; i /= 2)
            if (a[i] < a[i / 2])
                swap(a[i], a[i / 2]);
    }

    size--;
    while (size >= 1)
    {
        for (int i = 1; i <= size; i++)
            cout << "[" << i << "]" << a[i] << " \n"[i == size];

        a[1] = a[size];
        a[size--] = 0;

        int pos = 1;
        while (a[pos * 2])
        {
            int next = a[pos * 2] > a[pos * 2 + 1] && a[pos * 2 + 1] ? pos * 2 + 1 : pos * 2;
            //cout << "pos = " << pos << " next = " << next << "\n\n";
            if (a[pos] < a[next])
                break;
            swap(a[pos], a[next]);
            pos = next;
        }
    }

    system("pause");
    return 0;
}
