#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    TreeNode* mpParent;
    vector<TreeNode*> mChildren;

    TreeNode() : mpParent(nullptr) {}
    void AttachToParent(TreeNode* pParent)
    {
        mpParent = pParent;
        pParent->AddChild(this);
    }

    void Detach()
    {
        if (mpParent)
            mpParent->RemoveChild(this);
    }

    void AddChild(TreeNode* pChild)
    {
        mChildren.push_back(pChild);
    }

    void RemoveChild(TreeNode* pChild)
    {
        mChildren.erase(remove(mChildren.begin(), mChildren.end(), pChild));
    }

    int GetLeafCountFromThis()
    {
        int sum = 0;
        if (mChildren.size() == 0)
            return 1;
        for (auto pChild : mChildren)
            sum += pChild->GetLeafCountFromThis();
        return sum;
    }
};

int main()
{
    array<TreeNode, 50> treeNodes;
    vector<TreeNode*> rootNodes;

    int n;
    cin >> n;
    for (int current = 0; current < n; current++)
    {
        int parent;
        cin >> parent;
        if (parent == -1)
        {
            rootNodes.push_back(&treeNodes[current]);
        }
        else
        {
            treeNodes[current].AttachToParent(&treeNodes[parent]);
        }
    }

    int nodeToRemove;
    cin >> nodeToRemove;
    treeNodes[nodeToRemove].Detach();
    for (auto pRoot : rootNodes)
    {
        if (pRoot == &treeNodes[nodeToRemove])
        {
            rootNodes.erase(remove(rootNodes.begin(), rootNodes.end(), pRoot));
        }
    }

    int sum = 0;
    for (auto pRoot : rootNodes)
    {
        sum += pRoot->GetLeafCountFromThis();
    }
    cout << sum << endl;
}