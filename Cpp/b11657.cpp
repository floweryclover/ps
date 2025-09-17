#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using LL = long long;

int N, M;
vector<tuple<int, int, LL>> bus;
LL dist[501];

constexpr LL Inf = 10'000LL * 501LL * 6'000LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 501; ++i)
    {
        dist[i] = Inf;
    }

    bus.reserve(6000);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        bus.emplace_back(A, B, C);
    }

    dist[1] = 0;
    for (int v = 0; v < N; ++v)
    {
        for (const auto [A, B, C] : bus)
        {
            if (dist[A] == Inf)
            {
                continue;
            }
            
            dist[B] = min(dist[B], dist[A] + C);
        }
    }

    for (const auto [A, B, C] : bus)
    {
        if (dist[A] != Inf && dist[B] > dist[A] + C)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int B = 2; B <= N; ++B)
    {
        cout << (dist[B] != Inf ? dist[B] : -1) << "\n";
    }

    return 0;
}