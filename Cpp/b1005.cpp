#include <iostream>
#include <array>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

constexpr int UNKNOWN = 0xFFFFFFFF;

int GetShortest(int currentBuilding, int n, int k, const array<int, 100001>& d, const array<vector<int>, 100001>& buildRoot, array<int, 100001>& dp)
{
    if (dp[currentBuilding] != UNKNOWN)
        return dp[currentBuilding];

    if (buildRoot[currentBuilding].size() == 0)
        return dp[currentBuilding] = d[currentBuilding];

    int previousLongest = 0;
    for (auto iter = buildRoot[currentBuilding].cbegin(); iter != buildRoot[currentBuilding].cend(); iter++)
    {
        previousLongest = max(previousLongest, GetShortest(*iter, n, k, d, buildRoot, dp));
    }
    return dp[currentBuilding] = d[currentBuilding] + previousLongest;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    for (int i=0; i<testCases; i++)
    {
        int n, k;
        cin >> n >> k;
        array<int, 100001> d;
        for (int j=1; j<=n; j++)
            cin >> d[j];

        array<vector<int>, 100001> buildRoot;
        for (int j=1; j<=k; j++)
        {
            int x, y;
            cin >> x >> y;
            buildRoot[y].emplace_back(x);
        }
        
        int w;
        cin >> w;
        array<int, 100001> dp;
        memset(dp.data(), 0xFF, 4*100001);

        cout << GetShortest(w, n, k, d, buildRoot, dp) << endl;
    }
    return 0;
}