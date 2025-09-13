#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int A[1000001];
int prv[1000001];
int idx[1000001];
vector<int> LIS;

void Print(const int index)
{
    if (index == 0)
    {
        return;
    }

    Print(prv[index]);
    cout << A[index] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    A[0] = 0;
    prv[0] = 0;
    idx[0] = 0;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        if (LIS.empty())
        {
            LIS.push_back(A[i]);
            idx[0] = i;
            prv[i] = 0;
        }
        else if (LIS.back() < A[i])
        {
            LIS.push_back(A[i]);
            idx[LIS.size() - 1] = i;
            prv[i] = idx[LIS.size() - 2];
        }
        else
        {
            const auto iter = lower_bound(LIS.begin(), LIS.end(), A[i]);
            const int replaceIndex = iter - LIS.begin();
            *iter = A[i];
            idx[replaceIndex] = i;
            prv[i] = replaceIndex > 0 ? idx[replaceIndex - 1] : 0;
        }
    }

    cout << LIS.size() << endl;

    Print(idx[LIS.size() - 1]);

    return 0;
}