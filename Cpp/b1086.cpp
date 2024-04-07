#include <iostream>
#include <cstring>

using namespace std;

using LL = long long;

constexpr LL UNDEFINED = -1;

int n, k;
int remainderOfNumbers[15]; // [i] = i번째 수를 k로 나눈 나머지
int remainderOfPowers[51]; // [i] = 10^i 를 k로 나눈 나머지
int sizeOfNumbers[15];
LL memo[0b111111111111111 + 1][101]; // [i][j] = 상태가 i이고 현재까지의 나머지가 j일 때의 가능한 경우의 수

int GetRemainNumberCount(int flag)
{
    int remainNumbers = 0;
    for (int i=0; i<n; i++)
    {
        if ((flag & (1 << i)) == 0)
            remainNumbers++;
    }
    return remainNumbers;
}

LL Factorial(int n)
{
    LL result=1;
    for (int i=n; i>1; --i)
        result *= i;
    return result;
}

LL GetPossibleCases(int remainder, int selectedFlag)
{
    if (selectedFlag == (1<<n)-1)
    {
        if (remainder == 0)
            return 1;
        else
            return 0;
    }

    if (memo[selectedFlag][remainder] != UNDEFINED)
        return memo[selectedFlag][remainder];

    LL sum = 0;
    for (int i=0; i < n; i++)
    {
        if (selectedFlag & (1 << i))
            continue;

        int newRemainder = (remainder * remainderOfPowers[sizeOfNumbers[i]] + remainderOfNumbers[i]) % k;
        sum += GetPossibleCases(newRemainder, selectedFlag | (1<<i));
    }
    return memo[selectedFlag][remainder] = sum;
}

LL GetGcd(LL smaller, LL larger)
{
    LL temp;
    while (smaller > 0)
    {
        temp = larger % smaller;
        larger = smaller;
        smaller = temp;
    }
    return larger;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string inputs[15];
    for (int i=0; i<n; i++)
        cin >> inputs[i];
    cin >> k;

    remainderOfPowers[0] = 1 % k;
    remainderOfPowers[1] = 10 % k;
    for (int i=2; i<=50; i++)
    {
        remainderOfPowers[i] = ((10 % k) * remainderOfPowers[i-1]) % k;
    }

    for (int i=0; i<n; i++)
    {
        int size = inputs[i].length();
        int remainder = 0;
        int j = 0;
        for (int digit=size-1; digit>=0; --digit)
        {
            int asNumber = inputs[i][digit] - '0';
            remainder = ((asNumber % k) * (remainderOfPowers[j++]) + remainder) % k;
        }
        remainderOfNumbers[i] = remainder;
        sizeOfNumbers[i] = size;
    }

    for (int i=0; i<=0b111111111111111; i++)
        for (int j=0; j<=100; j++)
            memo[i][j] = UNDEFINED;
            
    LL totalCases = Factorial(n);
    LL possibleCases = GetPossibleCases(0, 0);
    LL gcd = GetGcd(possibleCases, totalCases);

    cout << possibleCases/gcd << "/" << totalCases/gcd << endl;

    return 0;
}