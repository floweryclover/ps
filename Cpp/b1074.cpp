#include <iostream>

using namespace std;

int Z(const int N, const int r, const int c)
{
    int cellWidth = 1;
    for (int i = 0; i < (N-1); i++)
    {
        cellWidth *= 2;
    }


    // 0 1
    // 2 3

    short pos = 0;

    if ((r+1) > cellWidth) pos += 2;
    if ((c+1) > cellWidth) pos += 1;


    if (N == 1)
    {
        return pos;
    }
    else
    {
        return (cellWidth*cellWidth)*pos + Z(N-1, r-(cellWidth*(pos/2)), c-(cellWidth*(pos%2)));
    }
}

int main()
{
    int N, r, c;
    cin >> N;
    cin >> r;
    cin >> c;

    cout << Z(N, r, c) << endl;
}