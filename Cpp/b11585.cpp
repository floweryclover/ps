#include <iostream>

using namespace std;

int N;
char R[2'000'000];
char P[1'000'000];
int Pi[1'000'000];

int GCD(const int a, const int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> R[i];
        R[N + i] = R[i];
    }

    int j = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
        if (i == 0)
        {
            continue;
        }

        while (j > 0 && P[j] != P[i])
        {
            j = Pi[j - 1];
        }
        if (P[j] == P[i])
        {
            ++j;
            Pi[i] = j;
        }
    }

    int cnt = 0;
    j = 0;
    for (int i = 0; i < 2 * N - 1; ++i)
    {
        while (j > 0 && P[j] != R[i])
        {
            j = Pi[j - 1];
        }
        if (P[j] == R[i])
        {
            if (j == N - 1)
            {
                ++cnt;
                j = Pi[j];
            }
            else
            {
                ++j;
            }
        }
    }

    const int gcd = GCD(cnt, N);
    cout << cnt / gcd << "/" << N / gcd << endl;

    return 0;
}