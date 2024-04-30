#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    for (int t=0; t<testCases; t++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        array<array<bool, 50>, 50> cabbage;
        array<array<bool, 50>, 50> visited;
        for (int i=0; i<50; i++)
        {
            for (int j=0; j<50; j++)
            {
                cabbage[i][j] = false;
                visited[i][j] = false;
            }
        }

        for (int i=0; i<k; i++)
        {
            int x, y;
            cin >> x >> y;
            cabbage[y][x] = true;
        }

        int earthwormCount = 0;
        for (int y=0; y<n; y++)
        {
            for (int x=0; x<m; x++)
            {
                if (!cabbage[y][x] || visited[y][x])
                    continue;

                earthwormCount++;

                queue<pair<int, int>> search;
                search.emplace(y, x);
                while (!search.empty())
                {
                    int searchY = search.front().first;
                    int searchX = search.front().second;
                    search.pop();

                    if (visited[searchY][searchX])
                        continue;
                    visited[searchY][searchX] = true;

                    if (searchY > 0     && cabbage[searchY-1][searchX] && !visited[searchY-1][searchX]) search.emplace(searchY-1, searchX);
                    if (searchY < n-1   && cabbage[searchY+1][searchX] && !visited[searchY+1][searchX]) search.emplace(searchY+1, searchX);
                    if (searchX > 0     && cabbage[searchY][searchX-1] && !visited[searchY][searchX-1]) search.emplace(searchY, searchX-1);
                    if (searchX < m-1   && cabbage[searchY][searchX+1] && !visited[searchY][searchX+1]) search.emplace(searchY, searchX+1);
                }
                
            }
        }
        cout << earthwormCount << "\n";
    }

    return 0;
}