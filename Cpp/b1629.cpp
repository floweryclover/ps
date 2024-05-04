#include <iostream>

using namespace std;

int ModuloPower(const int base, const int power, const int divisor)
{
    if (power == 0)
    {
        return 0;
    }
    else if (power == 1)
    {
        return base % divisor;
    }
    if (power % 2 != 0)
        return ((base % divisor) * static_cast<unsigned long long>(ModuloPower(base, power-1, divisor)) % divisor);
    else
    {
        unsigned long long halfResult = ModuloPower(base, power/2, divisor);
        return (halfResult * halfResult) % static_cast<unsigned long long>(divisor);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b,c;
    cin >> a >> b >> c;
    cout << ModuloPower(a, b, c) << endl;;
    return 0;
}