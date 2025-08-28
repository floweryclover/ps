#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> things;
vector<vector<int>> DP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    things.reserve(N);
    things.emplace_back(0, 0);

    for (int i=0; i<N; ++i)
    {
        int w, v;
        cin >> w >> v;
        things.emplace_back(w, v);
    }

    DP.resize(N + 1);
    for (int weight = 0; weight <= K; ++weight)
    {
        DP[0].push_back(0);
    }

    for (int currentIndex = 1; currentIndex <= N; ++currentIndex)
    {
        DP[currentIndex].resize(K+1, 0);
        for (int weight = 0; weight <= K; ++weight)
        {
            const auto [w, v] = things[currentIndex];
            DP[currentIndex][weight] = DP[currentIndex-1][weight];
            if (weight - w >= 0)
            {
                DP[currentIndex][weight] = max(DP[currentIndex-1][weight], DP[currentIndex-1][weight - w] + v);
            }
        }
    }

    int maximum = 0;
    for (int weight = 0; weight <= K; ++weight)
    {
        const int value = DP[N][weight];
        maximum = max(maximum, value);
    }
    cout << maximum << endl;

    return 0;
}