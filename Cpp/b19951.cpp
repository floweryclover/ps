#include <iostream>

using namespace std;

int N, M;
int H[100002];
int delta[1000002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> H[i];
    }

    for (int i = 1; i <= M; ++i)
    {
        int a, b, k;
        cin >> a >> b >> k;
        delta[a] += k;
        delta[b + 1] += -k;
    }

    int n = 0;
    for (int i = 1; i <= N; ++i)
    {
        n += delta[i];
        cout << H[i] + n << " ";
    }

    return 0;
}