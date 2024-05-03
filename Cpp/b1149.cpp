#include <iostream>
#include <array>

using namespace std;

enum Color
{
    R, G, B
};

struct Cost
{
    int R;
    int G;
    int B;
};

constexpr int UNDEFINED = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    array<Cost, 1000> colorCosts;

    for (int i=0; i<n; i++)
    {
        int rCost, gCost, bCost;
        cin >> rCost >> gCost >> bCost;

        colorCosts[i] = Cost { rCost, gCost, bCost };
    }

    array<array<int, 3>, 1000> DP;
    for (int i=0; i<1000; i++)
        for (int j=0; j<3; j++)
            DP[i][j] = UNDEFINED;

    array<Color, 3> colors = {R,G,B};
    DP[0][0] = colorCosts[0].R;
    DP[0][1] = colorCosts[0].G;
    DP[0][2] = colorCosts[0].B;
    for (int house = 1; house < n; house++)
    {
        for (int currentColor = 0; currentColor < 3; currentColor++)
        {
            if (currentColor == 0)
                DP[house][currentColor] = min(DP[house-1][1], DP[house-1][2]) + colorCosts[house].R;
            else if (currentColor == 1)
                DP[house][currentColor] = min(DP[house-1][0], DP[house-1][2]) + colorCosts[house].G;
            else
                DP[house][currentColor] = min(DP[house-1][0], DP[house-1][1]) + colorCosts[house].B;
        }
    }

    int minimumCost = 20000000;
    for (int color = 0; color<3; color++)
    {
        minimumCost = min(minimumCost, DP[n-1][color]);
    }
    cout << minimumCost << endl;

    return 0;
}