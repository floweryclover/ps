#include <iostream>
#include <array>
#include <vector>

using namespace std;

int n;
array<vector<pair<int, int>>, 10001> edges;

void DFS(int from, int& outFarthestNode, int& outFarthestLength)
{
    array<bool, 10001> visited;
    for (int i=0; i<10001; i++)
        visited[i] = false;

    outFarthestLength = 0;

    vector<pair<int, int>> search;
    search.emplace_back(from, 0);
    while (!search.empty())
    {
        auto currentNode = search.back().first;
        auto currentNodeDistance = search.back().second;
        search.pop_back();
        
        if (visited[currentNode])
            continue;
        visited[currentNode] = true;

        if (currentNodeDistance > outFarthestLength)
        {
            outFarthestNode = currentNode;
            outFarthestLength = currentNodeDistance;
        }

        for (const auto& edge : edges[currentNode])
        {
            if (!visited[edge.first])
                search.emplace_back(edge.first, currentNodeDistance + edge.second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=0; i<n-1; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;

        edges[src].emplace_back(dst, weight);
        edges[dst].emplace_back(src, weight);
    }

    if (n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    int farthestNode;
    int farthestNodeLength;

    DFS(1, farthestNode, farthestNodeLength);
    DFS(farthestNode, farthestNode, farthestNodeLength);
    cout << farthestNodeLength << endl;

    return 0;
}