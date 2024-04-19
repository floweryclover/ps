#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int n, m, x;
array<pair<int, pair<int, int>>, 10001> roads;
array<pair<int, pair<int, int>>, 10001> reveresedRoads;

constexpr pair<int, pair<int, int>> NO_ROAD = { -1, { -1, -1 } };
constexpr unsigned int UNDEFINED_TIME = 0xFFFFFFFF;

void BellmanFord(const array<pair<int, pair<int, int>>, 10001>& roadData, array<unsigned int, 1001>& outResult)
{
    outResult[x] = 0;
    for (int v=0; v<n-1; v++)
    {
        for (int e=0; e<m; e++)
        {
            int src = roadData[e].first;
            int dst = roadData[e].second.first;
            int time = roadData[e].second.second;

            if (outResult[src] != UNDEFINED_TIME && outResult[src] + time < outResult[dst])
                outResult[dst] = outResult[src] + time;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> x;
    for (int i=0; i<=10000; i++)
    {
        roads[i] = NO_ROAD;
        reveresedRoads[i] = NO_ROAD;
    }
        

    for (int i=0; i<m; i++)
    {
        int a, b, time;
        cin >> a >> b >> time;

        reveresedRoads[i] = { b, { a, time } };
        roads[i] = { a, { b, time } };
    }

    array<unsigned int, 1001> goResult;
    array<unsigned int, 1001> returnResult;

    memset(goResult.data(), 0xFF, 4*1001);
    memset(returnResult.data(), 0xFF, 4*1001);

    BellmanFord(reveresedRoads, goResult);
    BellmanFord(roads, returnResult);

    unsigned int maximumTime = 0;
    for (int i=1; i<=n; i++)
        maximumTime = max(maximumTime, goResult[i] + returnResult[i]);

    cout << maximumTime << endl;
    return 0;
}