#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

array<vector<pair<int, int>>, 801> edges;
constexpr int UNDEFINED = -1;
int n, e;

struct Vertice
{
    int vertice;
    int distance;

    bool operator<(const Vertice& rhs) const
    {
        return this->distance > rhs.distance;
    }
};

int Dijkstra(const int src, const int dst)
{
    array<bool, 801> visited;
    for (int i=0; i<801; i++)
        visited[i] = false;

    priority_queue<Vertice> priorityQueue;
    priorityQueue.emplace(Vertice { src, 0} );
    while (!priorityQueue.empty())
    {
        auto currentVertice = priorityQueue.top().vertice;
        auto currentDistance = priorityQueue.top().distance;

        priorityQueue.pop();

        if (visited[currentVertice])
            continue;
        visited[currentVertice] = true;

        if (currentVertice == dst)
            return currentDistance;

        for (const auto& edge : edges[currentVertice])
        {
            if (!visited[edge.first])
                priorityQueue.emplace(Vertice { edge.first, currentDistance + edge.second });
        }
    }
    
    return UNDEFINED;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;

    for (int i=0; i<e; i++)
    {
        int src, dst, dist;
        cin >> src >> dst >> dist;
        edges[src].emplace_back(dst, dist);
        edges[dst].emplace_back(src, dist);
    }

    int v1, v2;
    cin >> v1 >> v2;

    int srcToV1 = Dijkstra(1, v1);
    int srcToV2 = Dijkstra(1, v2);
    int v1ToV2 = Dijkstra(v1, v2);
    int v1ToDst = Dijkstra(v1, n);
    int v2ToDst = Dijkstra(v2, n);

    int case1 = (srcToV1 == UNDEFINED || v1ToV2 == UNDEFINED || v2ToDst == UNDEFINED) ? UNDEFINED : srcToV1 + v1ToV2 + v2ToDst;
    int case2 = (srcToV2 == UNDEFINED || v1ToV2 == UNDEFINED || v1ToDst == UNDEFINED) ? UNDEFINED : srcToV2 + v1ToV2 + v1ToDst;

    cout << min(case1, case2) << endl;

    return 0;
}