#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int UNDEFINED = -1;

bool CheckMinusCycle(const int n, const int m, const array<vector<pair<int, int>>, 501>& roads)
{
    array<bool, 501> checked;
    array<int, 501> distances;
    
    for (int i=0; i<501; i++)
    {
        checked[i] = false;
        distances[i] = UNDEFINED;
    }
    for (int src = 1; src <= n; src++)
    {
        if (checked[src])
            continue;

        vector<int> connectedNodes;
        queue<int> bfs;
        bfs.push(src);
        while (!bfs.empty())
        {
            auto currentNode = bfs.front();
            bfs.pop();
            
            if (checked[currentNode])
                continue;

            checked[currentNode] = true;
            connectedNodes.push_back(currentNode);
            for (const auto& road : roads[currentNode])
            {
                if (!checked[road.first])
                    bfs.push(road.first);
            }
        }

        distances[src] = 0;
        for (int i=0; i<connectedNodes.size(); i++)
        {
            for (const int currentNode : connectedNodes)
            {
                for (const auto& road : roads[currentNode])
                {
                    if (distances[road.first] == UNDEFINED || distances[road.first] > distances[currentNode] + road.second)
                    {
                        distances[road.first] = distances[currentNode] + road.second;
                    }
                }
            }
        }

        for (const int currentNode : connectedNodes)
        {
            for (const auto& road : roads[currentNode])
            {
                if (distances[road.first] > distances[currentNode] + road.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int t=0; t<tc; t++)
    {
        array<vector<pair<int, int>>, 501> roads;
        int n, m, w;
        cin >> n >> m >> w;
        for (int road=0; road<m; road++)
        {
            int s, e, t;
            cin >> s >> e >> t;

            roads[s].emplace_back(e, t);
            roads[e].emplace_back(s, t);
        }

        for (int wormhole=0; wormhole<w; wormhole++)
        {
            int s, e, t;
            cin >> s >> e >> t;

            roads[s].emplace_back(e, -t);
        }

        for (int i=0; i<501; i++)
        {

        }
        cout << (CheckMinusCycle(n, m, roads) ? "YES" : "NO") << "\n";
    }

    return 0;
}