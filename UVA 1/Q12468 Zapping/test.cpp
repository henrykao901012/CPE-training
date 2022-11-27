#include <algorithm>
#include <iostream>

using namespace std;
int main()
{
  int a, b;
  while (cin >> a >> b && a + b != -2)
  {
    int dis = abs(a - b);
    cout << min(dis, 100 - dis) << "\n";
  }

  system("pause");
  return 0;
}
