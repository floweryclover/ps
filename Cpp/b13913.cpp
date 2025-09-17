#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int track[100'001];
int T[100'001];

struct Search
{
    explicit Search(const int cur, const int prv, const int time)
    : Cur{cur}, Prv{prv}, Time{time}
    {

    }

    int Cur;
    int Prv;
    int Time;
};

void Print(const int cur)
{
    if (cur == -1)
    {
        return;
    }

    Print(track[cur]);
    cout << cur << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    memset(track, -1, sizeof(track));
    for (int i = 0; i <= 100'000; ++i)
    {
        T[i] = 100'001;
    }

    queue<Search> bfs;
    bfs.emplace(N, -1, 0);
    while (!bfs.empty())
    {
        const auto [cur, prv, time] = bfs.front();
        bfs.pop();

        if (time >= T[cur])
        {
            continue;
        }
        T[cur] = time;
        track[cur] = prv;

        if (cur + 1 <= 100'000 && time + 1 < T[cur + 1])
        {
            bfs.emplace(cur + 1, cur, time + 1);
        }
        
        if (cur - 1 >= 0 && time + 1 < T[cur - 1])
        {
            bfs.emplace(cur - 1, cur, time + 1);
        }
        if (cur * 2 <= 100'000 && time + 1 < T[cur * 2])
        {
            bfs.emplace(cur * 2, cur, time + 1);
        }
    }

    cout << T[K] << endl;
    Print(K);

    return 0;
}