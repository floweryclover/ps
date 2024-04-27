#include <iostream>
#include <array>
#include <cstring>

using namespace std;

struct SegmentTree
{
    static constexpr int UNDEFINED_NODE = -1;
    int* mNodes;
    int* mDatas;
    int mDataCount;
    SegmentTree() : mDataCount(0), mNodes(new int[1048576]), mDatas(new int[1048576])
    {
        for (int i=0; i<1048576; i++)
        {
            mNodes[i] = UNDEFINED_NODE;
            mDatas[i] = UNDEFINED_NODE;
        }
    }

    ~SegmentTree()
    {
        delete[] mNodes;
        delete[] mDatas;
    }

    void Insert(int data)
    {
        mDatas[mDataCount++] = data;
    }

    int Initialize(int currentNode)
    {
        if (currentNode > 1048575)
            return mDatas[currentNode - 1048576];
        else
        {
            return mNodes[currentNode] = max(Initialize(currentNode*2), Initialize(currentNode*2+1));
        }
            
    }

    int Search(int currentNode, int searchFrom, int searchTo, int rangeBegin, int rangeEnd)
    {
        if (searchTo < rangeBegin || searchFrom > rangeEnd)
            return UNDEFINED_NODE;
            
        if (currentNode > 1048575)
            return mDatas[currentNode - 1048576];

        if (rangeBegin >= searchFrom && rangeEnd <= searchTo)
        {
            return mNodes[currentNode];
        }
            
        else
        {
            int mid = (rangeBegin + rangeEnd) / 2;
            int left = Search(currentNode*2, searchFrom, searchTo, rangeBegin, mid);
            int right = Search(currentNode*2+1, searchFrom, searchTo, mid+1, rangeEnd);

            if (left == UNDEFINED_NODE || right == UNDEFINED_NODE)
                return (left == UNDEFINED_NODE ? right : left);
            else
                return max(left, right);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    SegmentTree segTree;
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        segTree.Insert(input);
    }
    segTree.Initialize(1);

    for (int i=m-1; i<n-m+1; i++)
    {
        cout << segTree.Search(1, i - (m-1), i + (m-1), 0, 1048575);
        if (i < n-m)
            cout << " ";
    }

    return 0;
}