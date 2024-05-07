#include <iostream>
#include <array>
#include <queue>

using namespace std;

struct EdgeInfo
{
    int src;
    int dst;
    int weight;

    bool operator<(const EdgeInfo& rhs) const
    {
        return this->weight > rhs.weight;
    }
};

struct UnionFind
{
    array<int, 10001> parents;

    UnionFind()
    {
        for (int i=0; i<10001; i++)
            parents[i] = i;
    }

    int Find(const int node)
    {
        if (parents[node] == node)
            return node;
        else
            return parents[node] = Find(parents[node]);
    }

    void Union(const int nodeA, const int nodeB)
    {
        int rootA = Find(nodeA);
        int rootB = Find(nodeB);

        parents[rootB] = rootA;
    }
};

int GetMst(priority_queue<EdgeInfo>& edges, int v)
{
    UnionFind unionFind;
    int sum = 0;
    int edgeCount = 0;
    while (!edges.empty() && edgeCount < v-1)
    {
        auto currentEdge = edges.top();
        edges.pop();

        if (unionFind.Find(currentEdge.src) == unionFind.Find(currentEdge.dst))
            continue;
        unionFind.Union(currentEdge.src, currentEdge.dst);

        sum += currentEdge.weight;
        edgeCount++;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<EdgeInfo> edges;
    int v, e;
    cin >> v >> e;

    for (int i=0; i<e; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;

        edges.emplace(EdgeInfo { src, dst, weight });
    }

    cout << GetMst(edges, v) << endl;

    return 0;
}