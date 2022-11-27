#include <bits/stdc++.h>
#define N 1000000

using namespace std;
int n, arr[N];

int longest_subseq_binary_search()
{
    vector<int> t;
    t.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > t.back())
        {
            t.push_back(arr[i]);
            len++;
        }
        else
        {
            int idx = distance(t.begin(), lower_bound(t.begin(), t.end(), arr[i]));
            t[idx] = arr[i];
        }
    }
    return len;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << longest_subseq_binary_search() << "\n";

    system("pause");
    return 0;
}