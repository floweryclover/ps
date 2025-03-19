#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    int level = 2;
    int lastNumber = 1;
    while (true)
    {
        int begin = lastNumber + 1;
        int end = lastNumber + 6 * (level-1);

        if (N >= begin && N <= end)
        {
            break;
        }

        level += 1;
        lastNumber = end;
    }

    cout << level << endl;

    return 0;
}