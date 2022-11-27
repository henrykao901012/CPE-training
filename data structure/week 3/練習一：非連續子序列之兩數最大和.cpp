#include <iostream>

using namespace std;
int main()
{
    int n, num[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int max = num[0] + num[2];
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            if (num[i] + num[j] > max)
                max = num[i] + num[j];

    cout << max << "\n";

    system("pause");
    return 0;
}