#include <iostream>

using namespace std;

int N;
int A[1001], B[1001], dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        cin >> B[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (abs(A[i] - B[j]) <= 4)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1); // i-j까지 점유했을 때의 최대 설치가능 횡단보도
            }
        }
    }

    cout << dp[N][N] << endl;

    return 0;
}