#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector<pair<int,int>> cities(n);
    for (int i=0; i<n; i++)
    {
        int cost, effect;
        cin >> cost >> effect;
        cities[i] = { cost, effect };
    }

    sort(cities.begin(), cities.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        double a_ratio = a.second/((double)a.first);
        double b_ratio = b.second/((double)b.first);

        if (a_ratio == b_ratio)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            else
                return a.first > b.first;
        }
        else
            return a_ratio > b_ratio;
    });

    int total_cost = 0;
    int total_effect = 0;
    int last_added_city = 0;
    while (total_effect < c)
    {
        last_added_city = 0;
    }
}