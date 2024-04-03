#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>

using namespace std;

string sentence;
array<string, 50> words;
int wordCount;
array<int, 51> cost;

constexpr int INF = 99;

int MinCost(string subString)
{
    int ret = INF;
    string a(subString);
    sort(a.begin(), a.end());
    for (int w=0; w<wordCount; w++)
    {
        if (words[w].length() != subString.length())
            continue;

        string b(words[w]);
        sort(b.begin(), b.end());

        if (a != b)
            continue;

        int cost = 0;
        for (int i=0; i<subString.length(); i++)
        {
            if (subString[i] != words[w][i])
                cost++;
        }
        ret = min(ret, cost);
    }
    return ret;
}

int Solve()
{
    for (int i=1; i<=sentence.length(); i++)
    {
        for (int j=0; j<i; j++)
        {
            string subString(sentence.begin()+j, sentence.begin()+i);
            int subStringCost = MinCost(subString);
            if (subStringCost == INF)
                continue;
            cost[i] = min(cost[i], cost[j] + subStringCost);
        }
    }
    return cost[sentence.length()];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (auto it = cost.begin(); it != cost.end(); it++)
        *it = INF;

    cin >> sentence >> wordCount;
    cost[0] = 0;
    
    for (int i=0; i<wordCount; i++)
    {
        cin >> words[i];
    }

    int result = Solve();
    cout << (result == INF ? -1 : result) << endl;

    return 0;
}