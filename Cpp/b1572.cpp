#include <iostream>
#include <cstring>

using namespace std;

class SegmentTree
{
private:
    static constexpr int UNDEFINED = 0xFFFFFFFF;
    int mBottom[65537]; // 131072개 // mBottom[i] = n == 숫자 i의 개수는 n개 있음
    int mNodes[131073]; // 마지막 레벨을 제외한 노드들, mNodes[i] = n == 노드 i 하위에는 n개의 입력값들이 있음
    int mRange; // k

    int GetLeftmostValue(int currentNode)
    {
        if (currentNode > 131071)
        {
            if (mBottom[currentNode-131072] == 0)
                return UNDEFINED;
            else
                return currentNode-131072; 
                
        }
        if (mNodes[currentNode] == 0)
            return UNDEFINED;
        int leftmost = GetLeftmostValue(currentNode*2);
        if (leftmost == UNDEFINED)
            leftmost = GetLeftmostValue(currentNode*2+1);
        return leftmost;
    }

    int GetMedianImpl(int currentNode, int leftCount) // (mRange/2)번째 값 찾기
    {
        if (currentNode > 131071)
            return currentNode - 131072;
        int leftChildCount;
        if (currentNode*2 > 131071)
            leftChildCount = mBottom[currentNode*2-131072];
        else
            leftChildCount = mNodes[currentNode*2];

        if (leftCount+leftChildCount < (mRange-1)/2)
        {
            return GetMedianImpl(currentNode*2+1, leftCount+leftChildCount);
        }
        else if (leftCount+leftChildCount == (mRange-1)/2)
        {
            return GetLeftmostValue(currentNode*2+1);
        }
        else
        {
return GetMedianImpl(currentNode*2, leftCount);
        }
            
    }

public:
    SegmentTree(int range) : mRange(range)
    {
        memset(mBottom, 0, 4*65537);
        memset(mNodes, 0, 4*131073);
    }

    void Insert(int value)
    {
        mBottom[value] += 1;
        int node = (value+131072) / 2;
        while (node > 0)
        {
            mNodes[node] += 1;
            node /= 2;
        }
    }

    void Remove(int value)
    {
        mBottom[value] -= 1;
        int node = (value+131072) / 2;
        while (node > 0)
        {
            mNodes[node] -= 1;
            node /= 2;
        }
    }

    int GetMedian()
    {
        return GetMedianImpl(1, 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    SegmentTree segmentTree(k);
    int inputs[250000];
    for (int i=0; i<n; i++)
    {
        cin >> inputs[i];
    }

    for (int i = 0; i<k-1; i++)
    {
        segmentTree.Insert(inputs[i]);
    }

    unsigned long long sum = 0;
    for (int i=k-1; i<n; i++)
    {
        segmentTree.Insert(inputs[i]);
        int median =  segmentTree.GetMedian();
        sum += median;
        segmentTree.Remove(inputs[i-(k-1)]);
    }

    cout << sum << endl;

    return 0;
}