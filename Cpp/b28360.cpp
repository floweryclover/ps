#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> hose[51];
double bucket[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int src, dst;
        cin >> src >> dst;
        hose[src].push_back(dst);
    }

    double maximum = 0.0;
    int maxIdx;
    bucket[1] = 100.0;
    for (int i = 1; i <= N; ++i)
    {
        if (hose[i].empty())
        {
            if (bucket[i] > maximum)
            {
                maximum = bucket[i];
                maxIdx = i;
            }
            continue;
        }

        for (const int dst : hose[i])
        {
            bucket[dst] += bucket[i] / hose[i].size();
        }
        bucket[i] = 0.0;
    }
    
    cout << bucket[maxIdx] << endl;

    return 0;
}