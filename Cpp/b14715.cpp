#include <iostream>
#include <cmath>

using namespace std;

int K;
bool isPrime[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> K;
    for (int i = 0; i <= 1000000; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= 1000000; ++p)
    {
        if (!isPrime[p])
        {
            continue;
        }

        for (int i = p * p; i <= 1000000; i += p)
        {
            isPrime[i] = false;
        }
    }

    int count = 0;
    while (K > 1)
    {
        for (int p = 2; p <= K; ++p)
        {
            if (isPrime[p] && K % p == 0)
            {
                K /= p;
                ++count;
            }
        }
    }

    cout << ceil(log(count) / log(2)) << endl;

    return 0;
}