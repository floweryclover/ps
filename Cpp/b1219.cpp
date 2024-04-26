#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct SalesRoute
{
    int src;
    int dst;
    long long result;
};

enum BellmanFordResult
{
    OK,
    GG,
    GEE,
};

int n, startingCity, endingCity, m;
int startingSale;
vector<SalesRoute> salesRoutes;
array<long long, 51> bellmanFord;
array<int, 51> prevCity;
constexpr long long UNDEFINED = 0xFFFFFFFF;

BellmanFordResult BellmanFord()
{
    for (int i=0; i<51; i++)
    {
        bellmanFord[i] = UNDEFINED;
        prevCity[i] = UNDEFINED;
    }

    bellmanFord[startingCity] = startingSale;
    for (int v = 0; v<n-1; v++)
    {
        for (const auto& salesRoute : salesRoutes)
        {
            if (bellmanFord[salesRoute.src] == UNDEFINED)
                continue;

            if (bellmanFord[salesRoute.dst] == UNDEFINED)
            {
                bellmanFord[salesRoute.dst] = bellmanFord[salesRoute.src] + salesRoute.result;
                prevCity[salesRoute.dst] = salesRoute.src;
            }
               
            else
            {
                if (bellmanFord[salesRoute.dst] < bellmanFord[salesRoute.src] + salesRoute.result)
                {
                    bellmanFord[salesRoute.dst] = bellmanFord[salesRoute.src] + salesRoute.result;
                    prevCity[salesRoute.dst] = salesRoute.src;
                }
            }
        }
    }

    if (bellmanFord[endingCity] == UNDEFINED)
        return GG;

    for (const auto& salesRoute : salesRoutes)
    {
        if (bellmanFord[salesRoute.src] == UNDEFINED)
            continue;

        if (bellmanFord[salesRoute.dst] < bellmanFord[salesRoute.src] + salesRoute.result)
        {
            array<bool, 51> visited;
            memset(visited.data(), 0, 51);
            queue<int> search;
            search.push(salesRoute.dst);

            while (!search.empty())
            {
                auto current = search.front();
                search.pop();

                if (visited[current])
                    continue;
                visited[current] = true;

                for (const auto& route : salesRoutes)
                {
                    if (route.src != current)
                        continue;
                    if (route.dst == endingCity)
                        return GEE;
                    if (visited[route.dst])
                        continue;
                    search.push(route.dst);
                }
            }
        }
    }


    return OK;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> startingCity >> endingCity >> m;
    for (int i=0; i<m; i++)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        salesRoutes.emplace_back(SalesRoute { src, dst, -cost });
    }

    for (int i=0; i<n; i++)
    {
        int sale;
        cin >> sale;
        if (i == startingCity)
            startingSale = sale;
        for (auto& salesRoute : salesRoutes)
        {
            if (salesRoute.dst == i)
            {
                salesRoute.result += sale;
            }
        }
    }

    auto result = BellmanFord();
    if (result == GG)
        cout << "gg" << endl;
    else if (result == GEE)
        cout << "Gee" << endl;
    else
        cout << bellmanFord[endingCity] << endl;

    return 0;
}