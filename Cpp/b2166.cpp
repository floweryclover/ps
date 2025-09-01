#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

using namespace std;

array<pair<double, double>, 10000> points;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double left = 0.0;
    double right = 0.0;
    for (int i=0; i<N; ++i)
    {
        const auto curPoint = points[i % N];
        const auto nextPoint = points[(i+1) % N];

        left += curPoint.first * nextPoint.second;
        right += nextPoint.first * curPoint.second;
    }

    const double area = 0.5 * abs(left - right);
    cout << fixed << setprecision(1) << round(area * 10.0) * 0.1 << endl;

    return 0;
}