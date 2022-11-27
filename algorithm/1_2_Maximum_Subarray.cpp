#include <bits/stdc++.h>

using namespace std;
const int neg_inf = numeric_limits<int>::min();

int get_max_crossing_sum(int arr[], int l, int m, int e)
{
    int sum = 0, left = neg_inf, right = neg_inf;
    for (int i = m; i >= l; i--) // ?????????
    {
        sum += arr[i];
        left = max(left, sum);
    }
    sum = 0;
    for (int i = m + 1; i <= e; i++)
    {
        sum += arr[i];
        right = max(right, sum);
    }
    return left + right;
}

int max_sum_subarray(int arr[], int front, int end)
{
    if (front == end)
        return arr[front];
    int mid = (front + end) / 2;
    return max({max_sum_subarray(arr, front, mid),
                max_sum_subarray(arr, mid + 1, end), get_max_crossing_sum(arr, front, mid, end)});
}

int main()
{
    int a[50000], n = 0;
    while (cin >> a[n++])
        continue;
    n--;
    // cout << "n = " << n << "\n";

    cout << max_sum_subarray(a, 0, n - 1) << "\n";

    system("pause");
    return 0;
}