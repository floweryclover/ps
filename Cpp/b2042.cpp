#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// Node개수 : 높이
// 1~2 : 2 2, 3
// 3~4 : 3 4, 5, 6, 7
// 5~8 : 4 8,9,10,11,12,13,14,15
// 9~16 : 5
// ...
// 높이 = LOG2(input-1)+2 (input > 0)
// 저장 시작 인덱스는 2^(LOG2(input-1)+1
// 전체 크기는 2^(높이)-1 = 2^(LOG2(1000000)-1)+2
class SumSegmentTree
{
private:
    long long* mNodes;
    int mCurrentInputCount;
    int mMaxInputCount;
    int mInsertOffset;
    int mInputCapacity;

    long long InitializeTree(int currentIndex)
    {
        if (currentIndex > mInsertOffset+mMaxInputCount)
            return 0;
        if (currentIndex >= mInsertOffset)
            return mNodes[currentIndex];

        mNodes[currentIndex] = InitializeTree(currentIndex*2);
        if (currentIndex*2+1 < mInsertOffset+mMaxInputCount)
            mNodes[currentIndex] += InitializeTree(currentIndex*2+1);
        return mNodes[currentIndex];
    }

    long long GetSumFromToImpl(int currentNode, int rangeBegin, int rangeEnd, int sumFrom, int sumTo) // real index, (mInsertOffset~) end, to : inclusive
    {
        if (rangeBegin >= sumFrom && rangeEnd <= sumTo)
            return mNodes[currentNode];

        if (rangeBegin > sumTo || rangeEnd < sumFrom)
            return 0;

        int rangeMid = rangeBegin + (rangeEnd-rangeBegin)/2;
        return GetSumFromToImpl(currentNode*2, rangeBegin, rangeMid, sumFrom, sumTo) + GetSumFromToImpl(currentNode*2+1, rangeMid+1, rangeEnd, sumFrom, sumTo);
    }

public:
    ~SumSegmentTree()
    {
        delete[] mNodes;
    }
    SumSegmentTree(int maxInputCount) : mMaxInputCount(maxInputCount), mCurrentInputCount(0), mNodes(new long long[4000004])
    {
        int height = ceil(log(maxInputCount)/log(2)) + 1;
        mInsertOffset = 1 << (height-1);
        mInputCapacity = 1 << (height-1);
    }

    void UpdateValue(int index, long long newValue)
    {
        int realIndex = mInsertOffset + (index-1);
        mNodes[realIndex] = newValue;
        realIndex /= 2;
        while (realIndex > 0)
        {
            mNodes[realIndex] = mNodes[realIndex*2];
            if (realIndex*2+1 < mInsertOffset+mMaxInputCount)
                mNodes[realIndex] += mNodes[realIndex*2+1];
            realIndex /= 2;
        }
    }

    void Insert(long long input)
    {
        mNodes[mInsertOffset+mCurrentInputCount] = input;
        mCurrentInputCount++;

        if (mCurrentInputCount == mMaxInputCount)
        {
            InitializeTree(1);
        }
            
    }

    long long GetSumFromTo(int from, int to)
    {
        return GetSumFromToImpl(1, mInsertOffset, mInsertOffset+mInputCapacity-1, mInsertOffset+from-1, mInsertOffset+to-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    SumSegmentTree sumTree(n);
    for (int i=0; i<n; i++)
    {
        long long input;
        cin >> input;
        sumTree.Insert(input);
    }

    for (int i=0; i<m+k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            sumTree.UpdateValue(b, c);
        else
            cout << sumTree.GetSumFromTo(b, c) << endl;
    }
    
    return 0;
}