#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>

using namespace std;

using ll = long long;

int N;
vector<ll> A;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll minimum = numeric_limits<ll>::max();
    tuple<ll, ll, ll> answer;

    for (int i = 0; i < N - 2; ++i)
    {
        int left = i + 1;
        int right = N - 1;
        while (left < right)
        {
            const ll sum = A[i] + A[left] + A[right];
            const ll absSum = abs(sum);
            if (absSum < minimum)
            {
                minimum = absSum;
                answer = { A[i], A[left], A[right] };
            }

            if (sum > 0)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
    }

    cout << get<0>(answer) << " " << get<1>(answer) << " " << get<2>(answer) << endl;

    return 0;
}