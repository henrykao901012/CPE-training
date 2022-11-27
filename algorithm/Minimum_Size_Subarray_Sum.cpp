#include <bits/stdc++.h>
#define N 10000000
#define inf numeric_limits<int>::max()

using namespace std;
int n, s, arr[N];
// const int inf = numeric_limits<int>::max();

int minSubArrayLen()
{
    int res = inf, left = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        while (left <= i && sum >= s)
        {
            res = min(res, i - left + 1);
            sum -= arr[left++];
        }
    }
    return res == inf ? 0 : res;
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minSubArrayLen() << "\n";

    system("pause");
    return 0;
}