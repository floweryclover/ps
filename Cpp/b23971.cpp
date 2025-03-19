#include <iostream>

using namespace std;

int H, W, N, M;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> N >> M;

    int areaHeight = N+1;
    int areaWidth = M+1;

    int rows = (H-1) / areaHeight + 1;
    int columns = (W-1) / areaWidth + 1;

    cout << rows * columns << endl;

    return 0;
}