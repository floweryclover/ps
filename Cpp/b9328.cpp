#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char map[100][100];
int visited[100][100];

pair<int, int> dirs[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, -1, sizeof(visited));

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        queue<pair<int, int>> bfs; // y, x
        vector<pair<int, int>> doors[26]; // [y, x]
        bool canOpen[26];
        int count = 0;
        memset(canOpen, 0, sizeof(canOpen));

        int h, w;
        cin >> h >> w;
        string input;
        for (int y = 0; y < h; ++y)
        {
            cin >> input;
            for (int x = 0; x < w; ++x)
            {
                map[y][x] = input[x];

                if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
                {
                    if (map[y][x] == '.')
                    {
                        bfs.emplace(y, x);
                    }
                    else if (map[y][x] == '$')
                    {
                        bfs.emplace(y, x);
                    }
                    else if (map[y][x] >= 'a' && map[y][x] <= 'z')
                    {
                        bfs.emplace(y, x);
                    }
                    else if (map[y][x] >= 'A' && map[y][x] <= 'Z')
                    {
                        doors[map[y][x] - 'A'].emplace_back(y, x);
                    }
                }
            }
        }

        string keys;
        cin >> keys;
        for (const char key : keys)
        {
            if (key == '0')
            {
                break;
            }

            canOpen[key - 'a'] = true;
            for (const auto [closedY, closedX] : doors[key - 'a'])
            {
                bfs.emplace(closedY, closedX);
            }
            doors[key - 'a'].clear();
        }

        while (!bfs.empty())
        {
            const auto [curY, curX] = bfs.front();
            bfs.pop();
            if (visited[curY][curX] == t)
            {
                continue;
            }
            visited[curY][curX] = t;
            const char block = map[curY][curX];

            if (block >= 'a' && block <= 'z')
            {
                canOpen[block - 'a'] = true;
                for (const auto [closedY, closedX] : doors[block - 'a'])
                {
                    bfs.emplace(closedY, closedX);
                }
                doors[block - 'a'].clear();
            }

            if (block == '$')
            {
                ++count;
            }
            
            for (const auto [dy, dx] : dirs)
            {
                if (curY + dy < 0 || curY + dy >= h || curX + dx < 0 || curX + dx >= w)
                {
                    continue;
                }

                const char nextBlock = map[curY + dy][curX + dx];
                if (nextBlock == '*' || visited[curY + dy][curX + dx] == t)
                {
                    continue;
                }

                if (nextBlock >= 'A' && nextBlock <= 'Z' && !canOpen[nextBlock - 'A'])
                {
                    doors[nextBlock - 'A'].emplace_back(curY + dy, curX + dx);
                    continue;
                }

                bfs.emplace(curY + dy, curX + dx);
            }
        }

        cout << count << "\n";
    }

    return 0;
}