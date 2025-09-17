#include <iostream>

using namespace std;

char students[100001][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            cin >> students[i];
        }

        if (N > 32)
        {
            cout << 0 << "\n";
            continue;
        }

        int minimum = 13;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int k = 0; k < N; ++k)
                {
                    if (i == j || j == k || k == i)
                    {
                        continue;
                    }
                    int dist = 0;
                    for (int l = 0; l < 5; ++l)
                    {
                        dist += (students[i][l] != students[j][l]);
                        dist += (students[j][l] != students[k][l]);
                        dist += (students[k][l] != students[i][l]);
                    }
                    minimum = min(minimum, dist);
                }
            }
        }
        cout << minimum << "\n";
    }

    return 0;
}