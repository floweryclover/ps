#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<string> unheards;
    vector<string> unheardUnseens;
    int count = 0;
    for (int i=0; i<n; i++)
    {
        string unheard;
        cin >> unheard;
        unheards.emplace(std::move(unheard));
    }

    for (int i=0; i<m; i++)
    {
        string unseen;
        cin >> unseen;
        if (unheards.find(unseen) != unheards.end())
        {
            unheardUnseens.emplace_back(std::move(unseen));
            count++;
        }
            
    }

    sort(unheardUnseens.begin(), unheardUnseens.end());
    cout << count << "\n";
    for (const auto& name : unheardUnseens)
        cout << name << "\n";
 
    return 0;
}