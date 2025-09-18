#include <iostream>

using namespace std;

int L;
char D[1'000'001];
int Pi[1'000'000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L;
    cin >> D;

    int j = 0;
    for (int i = 1; i < L; ++i)
    {
        while (j > 0 && D[j] != D[i])
        {
            j = Pi[j - 1];
        }
        
        if (D[j] == D[i])
        {
            ++j;
            Pi[i] = j;
        }
    }

    cout << L - Pi[L - 1] << endl;
    return 0;
}