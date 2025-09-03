#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

int N;
int costs[16][16];
uint32_t DP[16][1 << 16];

constexpr uint32_t Unknown = numeric_limits<uint32_t>::max();
constexpr uint32_t Infinite = Unknown - 1;

uint32_t Solve(const int curCity, const int visited)
{
    if (DP[curCity][visited] != Unknown)
    {
        return DP[curCity][visited];
    }
    DP[curCity][visited] = Infinite;

    if (visited == (1 << N) - 1)
    {
        return DP[curCity][visited] = costs[curCity][0] != 0 ? costs[curCity][0] : Infinite;
    }

    for (int nextCity = 1; nextCity < N; ++nextCity)
    {
        if ((visited & (1 << nextCity)) ||
            costs[curCity][nextCity] == 0)
        {
            continue;
        }

        const uint32_t nextSolve = Solve(nextCity, visited | (1 << nextCity));
        if (nextSolve != Infinite)
        {
            DP[curCity][visited] = min(DP[curCity][visited], nextSolve + costs[curCity][nextCity]); 
        }
    }

    return DP[curCity][visited];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(DP, Unknown, sizeof(DP));

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> costs[i][j];
        }
    }

    cout << Solve(0, 1) << endl;

    return 0;
}