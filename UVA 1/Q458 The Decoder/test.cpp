#include <iostream>

using namespace std;
int main()
{

    char str[1000000];
    while (gets(str))
    {
        for (int i = 0; str[i]; i++)
            str[i] += '*' - '1';
        cout << str << "\n";
    }

    system("pause");
    return 0;
}

//      1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
//      1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
//      1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5
