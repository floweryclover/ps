#include <iostream>
#include <vector>

using namespace std;

using ULL = long long;

ULL n, m, ans;
constexpr int Div = 1'000'000'007;

vector<pair<ULL, ULL>> factors;

// B ^ (Div - 1) % Div == 1
// B * B^(Div - 2) % Div == 1;
// B ^ (Div - 2) % Div == B ^ - 1

ULL Power(const ULL base, const ULL exp)
{
    if (exp == 1)
    {
        return base;
    }

    if (exp & 1)
    {
        return (base * Power(base, exp - 1)) % Div;
    }
    else
    {
        const ULL rt = Power(base, exp / 2);
        return (rt * rt) % Div;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    ans = 1;
    for (int p = 2; p * p <= 1'000'000'000; ++p)
    {
        // Sum = (b ^ n - 1) * (b - 1)^-1
        //     = ((b ^ n - 1) % Div) * (B^(Div - 2) % Div)) % Div
        if (n % p == 0)
        {
            ULL cnt = 0;
            while (n % p == 0)
            {
                n /= p;
                ++cnt;
            }
            
            factors.emplace_back(p, cnt);
        }
    }

    if (n != 1)
    {
        factors.emplace_back(n, 1);
    }

    for (const auto [base, exp] : factors)
    {
        const ULL left = Power(base, exp * m + 1) - 1;
        const ULL right = Power(base - 1, Div - 2);
        ans = (ans * ((left * right) % Div)) % Div;
    }

    cout << ans << endl;

    return 0;
}