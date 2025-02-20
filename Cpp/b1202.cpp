#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct WeightValue
{
    int M;
    int V;

    explicit WeightValue(const int m, const int v)
    : M{m}, V{v}
    {}

    bool operator<(const WeightValue& rhs) const
    {
        return V < rhs.V;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<WeightValue> weightValues;
    for (int i=0; i<n; ++i)
    {
        int m, v;
        cin >> m >> v;
        weightValues.emplace_back(m, v);
    }

    sort(weightValues.begin(), weightValues.end());

    multiset<int> bags;
    for (int i=0; i<k; ++i)
    {
        int c;
        cin >> c;
        bags.emplace(c);
    }

    uint64_t sum = 0;
    while (weightValues.size() > 0 && bags.size() > 0)
    {
        const auto currentWeightValue = weightValues.back();
        weightValues.pop_back();

        auto fitBag = bags.lower_bound(currentWeightValue.M);
        if (fitBag == bags.end())
        {
            continue;
        }

        sum += currentWeightValue.V;
        bags.erase(fitBag);
    }

    cout << sum << endl;

    return 0;
}