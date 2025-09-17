#include <iostream>

using namespace std;

int n, m, Q;
pair<int, int> queens[100];

int map[1001][1001]; // 0: 안전 1: 위험 2: 오브젝트 

constexpr pair<int, int> QueenDirs[] = {{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0},{-1,1},{0,1},{1,1}};
constexpr pair<int, int> KnightOffsets[] = {{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}, {2,1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        cin >> queens[i].first >> queens[i].second;
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int y, x;
        cin >> y >> x;
        map[y][x] = 2;

        for (const auto [dy, dx] : KnightOffsets)
        {
            const int py = y + dy;
            const int px = x + dx;
            if (py <= 0 || py > n || px <= 0 || px > m)
            {
                continue;
            }

            map[py][px] = max(map[py][px], 1);
        }
    }

    int P;
    cin >> P;
    for (int i = 0; i < P; ++i)
    {
        int y, x;
        cin >> y >> x;
        map[y][x] = 2;
    }

    for (int i = 0; i < Q; ++i)
    {
        const auto [y, x] = queens[i];
        map[y][x] = 2;
        for (const auto [dy, dx] : QueenDirs)
        {
            for (int range = 1; range <= 1000; ++range)
            {
                const int py = y + dy * range;
                const int px = x + dx * range;
                if (py <= 0 || py > n || px <= 0 || px > m || map[py][px] == 2)
                {
                    break;
                }

                map[py][px] = 1;
            }
        }
    }

    int safe = 0;
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= m; ++x)
        {
            if (map[y][x] == 0)
            {
                ++safe;
            }
        }
    }
    cout << safe <<endl;

    return 0;
}