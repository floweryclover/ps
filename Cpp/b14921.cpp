#include <iostream>

using namespace std;

int N, A[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    int minimum = 200'000'001;
    int best;
    int left = 1;
    int right = N;
    while (left < right)
    {
        const int sum = A[left] + A[right];
        if (abs(sum) < minimum)
        {
            minimum = abs(sum);
            best = sum;
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum < 0)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    cout << best << endl;

    return 0;
}