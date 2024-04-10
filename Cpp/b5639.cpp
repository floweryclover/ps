#include <iostream>
#include <array>

using namespace std;

struct TreeNode
{
    TreeNode() : mValue(0), mLeft(nullptr), mRight(nullptr) {}
    int mValue;
    TreeNode* mLeft;
    TreeNode* mRight;

    void SetValue(int value)
    {
        mValue = value;
    }

    void Insert(TreeNode* pNode)
    {
        if (pNode->mValue < mValue)
        {
            if (mLeft == nullptr)
                mLeft = pNode;
            else
                mLeft->Insert(pNode);
        }
        else if (pNode->mValue > mValue)
        {
            if (mRight == nullptr)
                mRight = pNode;
            else
                mRight->Insert(pNode);
        }
    }

    void PrintPostOrder()
    {
        if (mLeft)
            mLeft->PrintPostOrder();
        if (mRight)
            mRight->PrintPostOrder();
        cout << mValue << endl;
    }
};

class BinarySearchTree
{
public:
    BinarySearchTree() : mpRoot(nullptr) {}
    
    void PrintPostOrder()
    {
        if (mpRoot)
            mpRoot->PrintPostOrder();
    }

    void Insert(TreeNode* pNode)
    {
        if (mpRoot == nullptr)
            mpRoot = pNode;
        else
            mpRoot->Insert(pNode);
    }
private:
    TreeNode* mpRoot;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<TreeNode, 10000> nodes;
    BinarySearchTree bst;

    int input;
    int i = 0;
    while (!cin.eof())
    {
        cin >> input;
        nodes[i].SetValue(input);
        bst.Insert(&nodes[i]);
        i++;
    }

    bst.PrintPostOrder();

    return 0;
}