#include <iostream>
#include <array>

using namespace std;

constexpr int INVALID_CASE = -1;

int n, m;
int chickenCount;
int houseCount;
array<pair<int, int>, 100> houses;
array<pair<int, int>, 13> chickens;
array<array<int, 13>, 100> distances;

int GetCityChickenDistance(const array<int, 13>& currentChickens)
{
        int sum = 0;
        for (int house = 0; house < houseCount; house++)
        {
                int minimumDistance = 2147483647;
                for (int chicken = 0; chicken < m; chicken++)
                {
                        minimumDistance = min(minimumDistance, distances[house][currentChickens[chicken]]);
                }
                sum += minimumDistance;
        }
        return sum;
}

int Solve(int index, int remainder, array<int, 13> currentChickens)
{
        if (remainder == 0)
                return GetCityChickenDistance(currentChickens);
        if (index >= chickenCount)
                return INVALID_CASE;

        int withoutCurrent = Solve(index+1, remainder, currentChickens);
        currentChickens[m-remainder] = index;
        int withCurrent = Solve(index+1, remainder-1, currentChickens);

        if (withCurrent == INVALID_CASE && withoutCurrent == INVALID_CASE)
                return INVALID_CASE;
        else if (withCurrent != INVALID_CASE && withoutCurrent != INVALID_CASE)
                return min(withCurrent, withoutCurrent);
        else
                return withCurrent != INVALID_CASE ? withCurrent : withoutCurrent;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        chickenCount = 0;
        houseCount = 0;
        cin >> n >> m;

        for (int i=0; i<n; i++)
        {
                for (int j=0; j<n; j++)
                {
                        int input;
                        cin >> input;
                        if (input == 2)
                                chickens[chickenCount++] = { i, j };
                        else if (input == 1)
                                houses[houseCount++] = { i,j };
                }
        }

        for (int house = 0; house<houseCount; house++)
        {
                for (int chicken = 0; chicken < chickenCount; chicken++)
                {
                        int distance = abs(houses[house].first - chickens[chicken].first) + abs(houses[house].second - chickens[chicken].second);
                        distances[house][chicken] = distance;
                }
        }

        array<int, 13> currentChickens;
        cout << Solve(0, m, currentChickens) << endl;
}
