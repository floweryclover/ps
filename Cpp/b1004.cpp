#include <iostream>
#include <vector>

using namespace std;

bool IsInside(int x, int y, int cx, int cy, int r);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        int srcDepth = 0;
        int dstDepth = 0;
        for (int i = 0; i < n; ++i)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;
    
            const bool isSrcInside = IsInside(x1, y1, cx, cy, r);
            const bool isDstInside = IsInside(x2, y2, cx, cy, r);
            
            if (isSrcInside && isDstInside)
            {
                continue;
            }

            if (isSrcInside)
            {
                srcDepth += 1;
            }
            if (isDstInside)
            {
                dstDepth += 1;
            }
        }

        cout << srcDepth + dstDepth << endl;
    }

    return 0;
}

bool IsInside(const int x, const int y, const int cx, const int cy, const int r)
{
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r;
}