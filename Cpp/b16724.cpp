#include <iostream>
#include <cstring>

using namespace std;

int N, M;

char dir[1000][1000];
bool visited[1000][1000];
pair<int, int> root[1000][1000];

pair<int, int> Find(const int y, const int x)
{
    if (root[y][x] == pair<int, int>{ y, x })
    {
        return { y, x };
    }

    return root[y][x] = Find(root[y][x].first, root[y][x].second);
}

void Union(const int y1, const int x1, const int y2, const int x2)
{
    const auto root1 = Find(y1, x1);
    const auto root2 = Find(y2, x2);
    root[root2.first][root2.second] = root1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int y = 0; y < N; ++y)
    {
        char input[1001];
        cin >> input;
        for (int x = 0; x < M; ++x)
        {
            dir[y][x] = input[x];
            root[y][x] = { y, x };
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            pair<int, int> next;
            switch (dir[y][x])
            {
                case 'U': next = { y - 1, x }; break;
                case 'D': next = { y + 1, x }; break;
                case 'L': next = { y, x - 1 }; break;
                case 'R': next = { y, x + 1 }; break;
            }

            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)
            {
                continue;
            }

            Union(y, x, next.first, next.second);
        }
    }

    int count = 0;
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (root[y][x] == pair<int, int>{ y, x })
            {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}