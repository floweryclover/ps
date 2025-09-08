#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;

vector<int> U;
set<int> twoSums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    U.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        U.push_back(input);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            twoSums.insert(U[i] + U[j]);
        }
    }

    int maximum = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (twoSums.find(U[i] - U[j]) != twoSums.end()) // x + y + z = k -> x + y = k - z
            {
                maximum = max(maximum, U[i]);
            }
        }
    }

    cout << maximum << endl;

    return 0;
}