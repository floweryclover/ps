#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[1001][1001];
int N, M;
bool visited[1001][1001][2];

pair<int, int> dirs[4] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1} };

struct Node
{
    explicit Node(const int g, const int h, const int x, const int y, const bool canBreak)
    : G{g}, H{h}, X{x}, Y{y}, CanBreak{canBreak}
    {}

    int G;
    int H;
    int X;
    int Y;
    bool CanBreak;

    bool operator<(const Node& rhs) const
    {
        return G + H > rhs.G + rhs.H;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int y = 1; y <= N; ++y)
    {
        char input[1002];
        cin >> input;
        for (int x = 1; x <= M; ++x)
        {
            map[y][x] = input[x-1] - '0';
        }
    }

    memset(visited, 0, sizeof(visited));

    int minimum = 1001 * 1001;
    priority_queue<Node> astar;
    astar.emplace(1, N - 1 + M - 1, 1, 1, true);
    while (!astar.empty())
    {
        auto [g, h, x, y, canBreak] = astar.top();
        astar.pop();
        
        if (visited[y][x][canBreak ? 1 : 0])
        {
            continue;
        }
        visited[y][x][canBreak ? 1 : 0] = true;

        if (x == M && y == N)
        {
            minimum = min(minimum, g);
        }

        for (auto [dy, dx] : dirs)
        {
            if (x + dx < 1 || x + dx > M || y + dy < 1 || y + dy > N)
            {
                continue;
            }

            if (map[y + dy][x + dx] == 0)
            {
                astar.emplace(g + 1, abs(N - y - dy) + abs(M - x - dx), x + dx, y + dy, canBreak);
            }
            else if (canBreak)
            {
                astar.emplace(g + 1, abs(N - y - dy) + abs(M - x - dx), x + dx, y + dy, false);
            }
        }
    }

    cout << (minimum == 1001 * 1001 ? -1 : minimum) << endl;

    return 0;
}