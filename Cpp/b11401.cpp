#include <iostream>

using namespace std;

using ULL = unsigned long long;
int N, K;

constexpr int Div = 1'000'000'007;

ULL Pow(const ULL base, const int e)
{
    if (e == 1)
    {
        return base;
    }

    if (e & 1)
    {
        return (base % Div) * (Pow(base, e - 1) % Div) % Div;
    }
    else
    {
        const ULL half = Pow(base, e / 2);
        return (half % Div) * (half % Div) % Div;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    K = min(K, N - K);

    ULL a = 1;
    for (int i = N - K + 1; i <= N; ++i)
    {
        a = (a * i) % Div;
    }

    ULL b = 1;
    for (int i = 2; i <= K; ++i)
    {
        b = (b * i) % Div;
    }

    cout << ((a % Div) * (Pow(b, Div - 2) % Div)) % Div << endl;

    return 0;
}