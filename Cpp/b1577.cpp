#include <iostream>
#include <queue>
#include <set>
#include <cstring>

#define CURRENT_POS_Y (current.first)
#define CURRENT_POS_X (current.second)
#define CURRENT_POS_SINGLE_KEY (current.first * (m+1) + current.second)

using namespace std;

int n, m;
unsigned long long cases[101][101];

bool isBlocked[101*101][4];
constexpr int RIGHT = 0;
constexpr int TOP = 1;
constexpr int LEFT = 2;
constexpr int BOTTOM = 3;

void BFS()
{
    queue<pair<int, int>> search;
    set<int> visited;
    search.emplace(0, 0);
    cases[0][0] = 1;
    while(!search.empty())
    {
        auto current = search.front();
        search.pop();
        if (visited.find(CURRENT_POS_SINGLE_KEY) != visited.end())
            continue;

        visited.emplace(CURRENT_POS_SINGLE_KEY);

        if (CURRENT_POS_Y > 0 && !isBlocked[CURRENT_POS_SINGLE_KEY][BOTTOM])
            cases[CURRENT_POS_Y][CURRENT_POS_X] += cases[CURRENT_POS_Y-1][CURRENT_POS_X];
        if (CURRENT_POS_X > 0 && !isBlocked[CURRENT_POS_SINGLE_KEY][LEFT])
            cases[CURRENT_POS_Y][CURRENT_POS_X] += cases[CURRENT_POS_Y][CURRENT_POS_X-1];

        if (!isBlocked[CURRENT_POS_SINGLE_KEY][RIGHT])
        {
            if (CURRENT_POS_X < m && visited.find(CURRENT_POS_Y*(m+1) + CURRENT_POS_X+1) == visited.end())
                search.emplace(CURRENT_POS_Y, CURRENT_POS_X+1);
        }
        if (!isBlocked[CURRENT_POS_SINGLE_KEY][TOP])
        {
            if (CURRENT_POS_Y < n && visited.find((CURRENT_POS_Y+1)*(m+1) + CURRENT_POS_X) == visited.end())
                search.emplace(CURRENT_POS_Y+1, CURRENT_POS_X);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i<101; i++)
        memset(cases[i], 0, 8*101);
    for (int i=0; i<101*101; i++)
        memset(isBlocked[i], 0, 4);

    cin >> n >> m;

    int blockCount;
    cin >> blockCount;
    for (int i=0; i<blockCount; i++)
    {
        int y1, x1, y2, x2, temp;
        cin >> y1 >> x1 >> y2 >> x2;
        if (y2 < y1 || x2 < x1)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if (y2 > y1)
        {
            isBlocked[y1*(m+1) + x1][TOP] = true;
            isBlocked[y2*(m+1) + x2][BOTTOM] = true;
        }
        else
        {
            isBlocked[y1*(m+1) + x1][RIGHT] = true;
            isBlocked[y2*(m+1) + x2][LEFT] = true;
        }
    }

    BFS();

    cout << cases[n][m] << endl;
    return 0;
}