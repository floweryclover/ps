#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool isPrime[100001];
    for (int i = 0; i <= 100000; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= 100000; ++p)
    {
        if (!isPrime[p])
        {
            continue;
        }

        for (int i = p * p; i <= 100000; i += p)
        {
            isPrime[i] = false;
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        int remaining = N;
        for (int i = 2; i <= N; ++i)
        {
            if (!isPrime[i])
            {
                continue;
            }

            int count = 0;
            while (remaining % i == 0)
            {
                remaining /= i;
                ++count;
            }

            if (count > 0)
            {
                cout << i << " " << count << "\n";
            }
        }
        if (remaining == N)
        {
            cout << N << "\n";
        }
    }

    return 0;
}