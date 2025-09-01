#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cities;
    cities.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cities[i].first >> cities[i].second;
    }

    vector<int> dp;
    dp.resize(C+1, numeric_limits<int>::max());
    dp[0] = 0;
    for (int city = 0; city < N; ++city)
    {
        for (int customerCount = 1; customerCount <= C; ++customerCount)
        {
            const auto [currentCost, currentEffect] = cities[city];
            dp[customerCount] = min(dp[customerCount], currentCost * ((customerCount-1) / currentEffect + 1));

            if (customerCount >= currentEffect)
            {
                dp[customerCount] = min(dp[customerCount], dp[customerCount - currentEffect] + currentCost);
            }
        }
    }

    cout << dp[C] << endl;
    
    return 0;
}