#include <iostream>
#include <array>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
array<vector<pair<int, int>>, 100001> busCost;
bool visited[1001];
unsigned int currentCost[1001];

constexpr unsigned int UNDEFINED_COST = 0xFFFFFFFF;
constexpr unsigned int INFINITE = 0xFFFFFFFF;

int GetCheapestNext()
{
    int cheapestCost = INFINITE;
    int next = 0;
    for (int i=1; i <= n; i++)
    {
        if (visited[i])
            continue;
        if (currentCost[i] < cheapestCost)
        {
            cheapestCost = currentCost[i];
            next = i;
        }
    }
    return next;
}

unsigned int GetMinimumCost(int src, int dst)
{
    currentCost[src] = 0;

    int current;
    while ((current = GetCheapestNext()) > 0)
    {
        visited[current] = true;
        for (auto iter = busCost[current].cbegin(); iter != busCost[current].cend(); iter++)
        currentCost[iter->first] = min(currentCost[iter->first], currentCost[current] + iter->second);       
    }
    return currentCost[dst];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, 0, 1001);
    memset(currentCost, 0xFF, 4*1001); // INFINITE

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        busCost[a].emplace_back(b, cost);
    }
    int src, dst;
    cin >> src >> dst;

    cout << GetMinimumCost(src, dst) << endl;

    return 0;
}