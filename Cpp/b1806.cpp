#include <iostream>

using namespace std;

int N, S;

int* Inputs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    Inputs = new int[N];
    for (int i=0; i<N; ++i)
    {
        cin >> Inputs[i];
    }

    int minimumLength = 0x7FFFFFFF;

    int begin = 0;
    int end = 1;
    int sum = Inputs[begin];
    while (end <= N)
    {
        if (end > begin && sum >= S)
        {
            minimumLength = min(minimumLength, end-begin);
            sum -= Inputs[begin];
            begin += 1;
        }
        else
        {
            if (end < N)
            {
                sum += Inputs[end];
            }
            end += 1;
        }
    }

    cout << (minimumLength == 0x7FFFFFFF ? 0 : minimumLength) << endl;

    return 0;
}