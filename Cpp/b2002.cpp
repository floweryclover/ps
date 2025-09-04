#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int N;
unordered_map<string, int> orders;
set<int> remaining;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    string input;
    for (int i = N - 1; i >= 0; --i)
    {
        cin >> input;
        orders.emplace(input, i);
        remaining.insert(i);
    }
    
    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        if (remaining.upper_bound(orders[input]) != remaining.end())
        {
            answer += 1;
        }
        remaining.erase(orders[input]);
    }

    cout << answer << endl;

    return 0;
}