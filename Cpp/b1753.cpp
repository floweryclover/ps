#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

int v, e, src;
array<vector<pair<int, int>>, 20001> edges;
array<int, 20001> distances;

constexpr int INFINITE = -1;

struct NodeInfo
{
    int node;
    int dist;

    bool operator<(const NodeInfo& rhs) const
    {
        return this->dist > rhs.dist;
    }
};

void Dijkstra()
{
    array<bool, 20001> visited;
    for (int i=0; i<20001; i++)
    {
        visited[i] = false;
        distances[i] = INFINITE;
    }
        
    priority_queue<NodeInfo> search;
    search.emplace(NodeInfo { src, 0 });
    while (!search.empty())
    {
        auto currentNode = search.top().node;
        auto currentDistance = search.top().dist;
        search.pop();

        if (visited[currentNode])
            continue;
        visited[currentNode] = true;

        distances[currentNode] = currentDistance;
        for (const auto& edge : edges[currentNode])
        {
            if (!visited[edge.first])
                search.emplace(NodeInfo { edge.first, currentDistance + edge.second }); 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;
    cin >> src;

    for (int i=0; i<e; i++)
    {
        int src_, dst_, weight;
        cin >> src_ >> dst_ >> weight;
        edges[src_].emplace_back(dst_, weight);
    }

    Dijkstra();

    for (int i=1; i<=v; i++)
    {
        if (distances[i] == INFINITE)
            cout << "INF\n";
        else
            cout << distances[i] << "\n";
    }
    return 0;
}