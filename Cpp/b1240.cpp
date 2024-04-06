#include <iostream>
#include <array>
#include <queue>
#include <cstring>

using namespace std;

constexpr int UNDEFINED = -1;

int n, m;
array<array<int, 1001>, 1001> adjacentMatrix;

int BFS(int src, int dst)
{
    queue<pair<int, int>> search; // pair<node, distance>
    array<bool, 1001> visited;
    memset(visited.data(), 0, 1001);

    search.emplace(src, 0);
    while (!search.empty())
    {
        int currentNode = search.front().first;
        int currentDistance = search.front().second;
        search.pop();
        if (visited[currentNode])
            continue;

        visited[currentNode] = true;

        if (currentNode == dst)
            return currentDistance; 

        for (int i = 1; i <= n ; i++)
        {
            if (i == currentNode || adjacentMatrix[currentNode][i] == UNDEFINED || visited[i])
                continue;
            search.emplace(i, currentDistance + adjacentMatrix[currentNode][i]);
        }
    }
    return UNDEFINED; // No Entry
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<1001; i++)
    {
        for (int j=0; j<1001; j++)
        {
            if (i==j)
                adjacentMatrix[i][i] = 0;
            else
            {
                adjacentMatrix[i][j] = UNDEFINED;
                adjacentMatrix[j][i] = UNDEFINED;
            }
        }
    }

    cin >> n >> m;

    for (int i=0; i<n-1; i++)
    {
        int a, b, distance;
        cin >> a >> b >> distance;
        adjacentMatrix[a][b] = distance;
        adjacentMatrix[b][a] = distance;
    }

    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << BFS(a, b) << endl;
    }

    return 0;
}