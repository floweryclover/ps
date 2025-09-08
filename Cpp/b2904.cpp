#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N;
bool isPrime[1000001];
int primeFactorization[101][100000];
int primes[100000];
int desired[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i <= 1'000'000; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= 1'000'000; ++p)
    {
        if (!isPrime[p])
        {
            continue;
        }

        for (int i = p * p; i <= 1'000'000; i += p)
        {
            isPrime[i] = false;
        }
    }

    int primeCount = 1;
    for (int p = 2; p <= 1'000'000; ++p)
    {
        if (isPrime[p])
        {
            primes[primeCount] = p;
            ++primeCount;
        }
    }

    memset(primeFactorization, 0, sizeof(primeFactorization));
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= primeCount; ++j)
        {
            if (n == 1)
            {
                break;
            }
            while (n % primes[j] == 0)
            {
                n /= primes[j];
                primeFactorization[i][j] += 1;
            }
        }
    }

    memset(desired, 0, sizeof(desired));
    for (int i = 1; i <= primeCount; ++i)
    {
        int count = 0;
        for (int j = 1; j <= N; ++j)
        {
            count += primeFactorization[j][i];
        }
        desired[i] = count / N;
    }

    int best = 1;
    int count = 0;
    for (int primeIndex = 1; primeIndex <= primeCount; ++primeIndex)
    {
        const int prime = primes[primeIndex];
        if (desired[primeIndex] > 0)
        {
            best *= pow(prime, desired[primeIndex]);
        }
        
        for (int i = 1; i <= N; ++i)
        {
            const int needCount = desired[primeIndex] - primeFactorization[i][primeIndex];
            if (needCount <= 0)
            {
                continue;
            }

            count += needCount;
        }
    }
    
    cout << best << " " << count << endl;
   
    return 0;
}