#include <iostream>
#include <array>
#include <vector>
#include <stack>

using namespace std;

array<vector<pair<int, int>>, 100001> edges;

void DFS(const int beginNode, int& outFarthestNode, int& outFarthestNodeDistance)
{
    array<bool, 100001> visited;
    for (int i=0; i<100001; i++)
        visited[i] = false;

    outFarthestNodeDistance = 0;
    stack<pair<int, int>> search;
    search.emplace(beginNode, 0);
    while (!search.empty())
    {
        int currentNode = search.top().first;
        int currentDistance = search.top().second;
        search.pop();
        
        if (visited[currentNode])
            continue;
        visited[currentNode] = true;

        if (currentDistance > outFarthestNodeDistance)
        {
            outFarthestNode = currentNode;
            outFarthestNodeDistance = currentDistance;
        }

        for (const auto& edge : edges[currentNode])
        {
            if (!visited[edge.first])
                search.emplace(edge.first, currentDistance + edge.second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v;
    cin >> v;

    for (int i=0; i<v; i++)
    {
        int src;
        cin >> src; // 정점번호

        int input;
        int dst = -1;
        int weight = -1;
        cin >> input;
        while (input != -1)
        {
            if (dst == -1)
                dst = input;
            else
            {
                weight = input;
                edges[src].emplace_back(dst, weight);
                dst = -1;
                weight = -1;
            }
            cin >> input;
        }
    }

    int farthestNode, farthestNodeDistance;
    DFS(1, farthestNode, farthestNodeDistance);
    DFS(farthestNode, farthestNode, farthestNodeDistance);
    cout << farthestNodeDistance << endl;

    return 0;
}