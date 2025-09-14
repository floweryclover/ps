#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[1000001];
vector<int> LIS;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];

        if (LIS.empty())
        {
            LIS.push_back(A[i]);
        }
        else if (LIS.back() < A[i])
        {
            LIS.push_back(A[i]);
        }
        else
        {
            const auto iter = lower_bound(LIS.begin(), LIS.end(), A[i]);
            *iter = A[i];
        }
    }

    cout << LIS.size() << endl;

    return 0;
}