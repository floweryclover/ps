#include <iostream>
#include <cstring>

using namespace std;

bool isPrime[100001];
int A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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

    int count = 0;
    cin >> A >> B;
    for (int i = A; i <= B; ++i)
    {
        int num = i;
        int primeCount = 0;
        for (int p = 2; p <= num; ++p)
        {
            if (!isPrime[p])
            {
                continue;
            }
            if (num == 1)
            {
                break;
            }
            while (num % p == 0)
            {
                num /= p;
                primeCount += 1;
            }
        }

        if (isPrime[primeCount])
        {
            count += 1;
        }
    }
    cout << count << endl;

    return 0;
}