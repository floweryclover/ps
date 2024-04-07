#include <iostream>
#include <array>
#include <cstring>

using namespace std;
// 1~4000000 소수 개수: 283146
constexpr int PRIME_COUNT = 283146;
array<int, PRIME_COUNT> primes;

bool IsPrime(int num)
{
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    
    for (int i=3; i*i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isPrime[4000001];
    for (int i=0; i<=4000000; i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i <= 4000000; i++)
    {
        if (isPrime[i])
        {
            for (int j=i*i; j<=4000000; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    int sum = 0;
    for (int i=0; i<=4000000; i++)
    {
        if (isPrime[i])
            primes[count++] = i;
    }

    int n;
    cin >> n;
    int caseCount = 0;
    for (count = 1; count <= 1040; count++)
    {
        int sum = 0;
        int start = 0;
        for (int i=0; i<count; i++)
        {
            sum += primes[i];
        }

        while (sum < n)
        {
            sum -= primes[start];
            sum += primes[start+count];
            start++;
        }

        if (sum == n)
            caseCount++;
    }

    cout << caseCount << endl;
    return 0;
}