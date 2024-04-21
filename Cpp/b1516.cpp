#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<vector<int>, 501> build;
array<int, 501> buildTime;
array<int, 501> memo;

constexpr int UNKNOWN_TIME = -1;

int n;

int GetMinimumTime(int currentBuilding)
{
    if (memo[currentBuilding] != UNKNOWN_TIME)
        return memo[currentBuilding];

    int longestPrev = 0;
    for (int prevBuilding : build[currentBuilding])
        longestPrev = max(longestPrev, GetMinimumTime(prevBuilding));

    return memo[currentBuilding] = buildTime[currentBuilding] + longestPrev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0; i<501; i++)
        memo[i] = UNKNOWN_TIME;

    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int input;
        cin >> input;
        buildTime[i] = input;
        while (true)
        {    
            cin >> input;
            if (input == -1)
                break;

            build[i].push_back(input);
        }
    }

    for (int i=1; i<=n; i++)
        cout << GetMinimumTime(i) << endl;

    return 0;
}