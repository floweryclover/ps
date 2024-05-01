#include <iostream>
#include <array>
#include <queue>

using namespace std;

int n, k;

int BFS()
{
    array<bool, 100001> visited;
    for (int i=0; i<100001; i++)
        visited[i] = false;

    queue<pair<int, int>> search;
    search.emplace(n, 0);
    int returnValue;
    while (!search.empty())
    {
        int currentLocation = search.front().first;
        int currentTimeTaken = search.front().second;
        search.pop();

        if (visited[currentLocation])
            continue;
        visited[currentLocation] = true;

        if (currentLocation == k)
        {
            returnValue = currentTimeTaken;
            break;
        }

        if (currentLocation > 0 && !visited[currentLocation-1])
            search.emplace(currentLocation-1, currentTimeTaken+1);
        if (currentLocation < 100000 && !visited[currentLocation+1])
            search.emplace(currentLocation+1, currentTimeTaken+1);
        if (currentLocation*2 <= 100000 && !visited[currentLocation*2])
            search.emplace(currentLocation*2, currentTimeTaken+1);
    }
    return returnValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    cout << BFS() << endl;
    return 0;
}