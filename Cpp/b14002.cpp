#include <iostream>

using namespace std;

int N;
int A[1001];
int prv[1001];
int dp[1001];

void Print(const int cur)
{
    if (cur == 0)
    {
        return;
    }

    Print(prv[cur]);
    cout << A[cur] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    
    A[0] = prv[0] = dp[0] = 0;
    int longest = 0;
    int longestIdx;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];

        int prvLongest = 0;
        int prvIdx;
        for (int j = 1; j < i; ++j)
        {
            if (A[j] >= A[i])
            {
                continue;
            }

            if (dp[j] > prvLongest)
            {
                prvLongest = dp[j];
                prvIdx = j;
            }
        }

        dp[i] = prvLongest + 1;
        if (dp[i] > 1)
        {
            prv[i] = prvIdx;
        }

        if (dp[i] > longest)
        {
            longest = dp[i];
            longestIdx = i;
        }
    }

    cout << longest << endl;
    Print(longestIdx);

    return 0;
}