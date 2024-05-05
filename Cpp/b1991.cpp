#include <iostream>
#include <array>

using namespace std;

array<pair<int, int>, 30> treeNodes;

constexpr int NONE = -1;

void PreOrder(const int node)
{
    cout << static_cast<char>(node + 'A');
    if (treeNodes[node].first != NONE)
        PreOrder(treeNodes[node].first);
    if (treeNodes[node].second != NONE)
        PreOrder(treeNodes[node].second);
}

void InOrder(const int node)
{
    if (treeNodes[node].first != NONE)
        InOrder(treeNodes[node].first);
    cout << static_cast<char>(node + 'A');
    if (treeNodes[node].second != NONE)
        InOrder(treeNodes[node].second);
}

void PostOrder(const int node)
{
    if (treeNodes[node].first != NONE)
        PostOrder(treeNodes[node].first);
    if (treeNodes[node].second != NONE)
        PostOrder(treeNodes[node].second);
    cout << static_cast<char>(node + 'A');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0; i<30; i++)
        treeNodes[i] = pair<int, int> { NONE, NONE };

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        treeNodes[parent - 'A'].first = left == '.' ? NONE : left - 'A';
        treeNodes[parent - 'A'].second = right == '.' ? NONE : right - 'A';
    }

    PreOrder(0); cout << endl;
    InOrder(0); cout << endl;
    PostOrder(0); cout << endl;

    return 0;
}