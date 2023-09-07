#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<pair<int, int>> table(41);
    table[0] = { 1, 0 };
    table[1] = { 0, 1 };

    for (int i=2; i<=40; i++)
    {
        table[i] = { table[i-2].first+table[i-1].first , table[i-2].second+table[i-1].second };
    }

    for (int i=0; i<t; i++)
    {
        int input;
        cin >> input;
        cout << table[input].first << " " << table[input].second << endl;
    }
}