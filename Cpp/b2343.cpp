#include <iostream>
#include <vector>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    vector<int> lengths;
    int begin = 0;
    int end = 0;

    cin >> N >> M;
 
    for (int i=0; i<N; ++i)
    {
        int length;
        cin >> length;
        lengths.push_back(length);

        begin = max(begin, length);
        end += length;
    }

    while (begin < end)
    {
        const int mid = (begin + end) / 2;
        int remaining = 0;
        int count = 0;

        for (const int length : lengths)
        {
            if (length > remaining)
            {
                count += 1;
                remaining = mid;
            }
            remaining -= length;

            if (count > M)
            {
                break;
            }
        }

        if (count > M)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    cout << begin << endl;

    return 0;
}