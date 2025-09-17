#include <iostream>
#include <cstring>

using namespace std;

int D;

using ULL = unsigned long long;
constexpr int N = 8;
ULL M[9][9] = 
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 1, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 0, 1, 0, 1, 0 },
};

constexpr ULL Div = 1'000'000'007;

void Power(const int p, ULL out[9][9])
{
    if (p == 1)
    {
        memcpy(out, M, sizeof(M));
        return;
    }

    ULL in[9][9];
    if (p & 1)
    {
        Power(p - 1, in);
    }
    else
    {
        Power(p / 2, in);
    }

    memset(out, 0, sizeof(M));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= N; ++k)
            {
                out[i][j] = (out[i][j] % Div + (((p & 1) ? M[i][k] : in[i][k]) % Div * (in[k][j] % Div)) % Div) % Div; 
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> D;
    ULL matrix[9][9];
    Power(D, matrix);
    cout << matrix[1][1] << endl;
    return 0;
}