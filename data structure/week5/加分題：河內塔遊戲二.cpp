#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int pow(int a, int b)
{
    int ans = 1;
    while (b--)
        ans *= a;
    return ans;
}

void print_stack(stack<int> s)
{
    stack<int> get;
    while (!s.empty())
    {
        get.push(s.top());
        s.pop();
    }
    while (!get.empty())
    {
        cout << " " << get.top();
        get.pop();
    }
    cout << "\n";
}

void hanoi(int n, int a, int b, int c)
{
    static int count = 0;
    static const int total = n;
    static bool construct = 0;
    static stack<int> plate[3];
    if (!construct)
    {
        int get = n;
        while (get--)
            plate[0].push(get + 1);
        construct = 1;
    }
    if (n > 0)
    {
        hanoi(n - 1, a, c, b);
        if (count == 0)
        {
            cout << "***********************************\n";
            cout << "Initial State:\n";
            for (int i = 0; i < 3; i++)
            {
                cout << char(i + 'A') << ":";
                print_stack(plate[i]);
            }
        }

        plate[c - 1].push(plate[a - 1].top());
        plate[a - 1].pop();
        //cout << "\n\nmove  " << n << "  from  " << char(a + 'A' - 1) << "  to  " << char(c + 'A' - 1) << "  ";

        if ((count + 1) % 5 == 0 && pow(2, total) - 1 != count + 1)
        {
            cout << "***********************************\n";
            printf("After Moved %d Times:\n", count + 1);
            for (int i = 0; i < 3; i++)
            {
                cout << char(i + 'A') << ":";
                print_stack(plate[i]);
            }
        }
        else if (pow(2, total) - 1 == count + 1)
        {
            cout << "***********************************\n";
            printf("Total Moved %d Times:\n", count + 1);
            for (int i = 0; i < 3; i++)
            {
                cout << char(i + 'A') << ":";
                print_stack(plate[i]);
            }
        }
        count++;
        hanoi(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "Number of Discs: " << n << "\n";
    hanoi(n, 1, 2, 3);

    system("pause");
    return 0;
}
