#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> needs;

int Simulate(int K);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    needs.resize(N);
    for (int i=0; i<N; ++i)
    {
        cin >> needs[i];
    }

    int left = 1;
    int right = 100000 * 10000;
    int mid;
    int answer;
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        const int count = Simulate(mid);
        if (count > M)
         {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
            answer = mid;
        }
    }

    cout << answer << endl;

    return 0;
}

int Simulate(const int K)
{
    int count = 0;
    int remaining = 0;
    for (int need : needs)
    {
        if (need > K)
        {
            return 10000 * 100000;
        }

        if (need > remaining)
        {
            count += 1;
            remaining = K;
        }

        remaining -= need;
    }
    return count;
}