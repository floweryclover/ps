#include <iostream>
#include <array>
#include <cstring>

using namespace std;

constexpr int OFFSET = 10000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int* count = new int[20000001];
    memset(count, 0, 4*20000001);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        count[input+OFFSET] += 1;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++)
    {
        int input;
        cin >> input;
        cout << count[input+OFFSET];

        if (i<m-1)
            cout << " ";
    }

    delete[] count;
    return 0;
}