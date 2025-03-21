#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> requests;
    requests.reserve(10000);
    for (int i=0; i<N; ++i)
    {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    int M;
    cin >> M;

    sort(requests.begin(), requests.end());

    vector<int> sum;
    sum.resize(N+1);
    sum[0] = 0; // sum[i]: i 이전까지의 총합
    for (int i=0; i<N; ++i)
    {
        sum[i+1] = sum[i] + requests[i];
    }

    if (sum[N] <= M)
    {
        cout << requests[N-1] << endl;
        return 0;
    }

    int maximum = 0;
    for (int i=0; i<N; ++i)
    {
        // i부터는 남은 양 분배
        const int atLeast = requests[i];
        const int quotient = (M-sum[i]) / (N-i);

        maximum = max(maximum, quotient);
    }

    cout << maximum << endl;

    return 0;
}