#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int n, k;
array<int, 100> coins;
array<array<int, 10001>, 2> counts;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i=0; i<n; ++i)
    {
        cin >> coins[i];
    }

    int workingIndex = 0;
    memset(counts[workingIndex].data(), 0, sizeof(int) * 10001);
    for (int coinIndex = 0; coinIndex < n; ++coinIndex)
    {
        const int coin = coins[coinIndex];
        for (int value = 0; value <= k; ++value)
        {
            counts[workingIndex][value] = counts[1 - workingIndex][value];
            
            if (value == coin)
            {
                counts[workingIndex][value] += 1;
            }
            else if (value > coin)
            {
                counts[workingIndex][value] += counts[workingIndex][value-coin];
            }
        }
        workingIndex = 1 - workingIndex;
    }

    cout << counts[1 - workingIndex][k] << endl;

    return 0;
}