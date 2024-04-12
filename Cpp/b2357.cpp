#include <iostream>
#include <array>
#include <cmath>

using namespace std;

class MinMaxTree
{
private:
    static constexpr int MINIMUM_NOT_FOUND = 1000000001;
    static constexpr int MAXIMUM_NOT_FOUND = 0;
    int* mLastLevel; // 마지막 레벨에 입력되는 실제 데이터들
    pair<int, int>* mNodes; // 마지막 레벨을 제외한 노드들, 구간 내 <최소, 최대> 값 저장
    int mInputCount;
    int mNodeCount; // 마지막 레벨의 데이터 개수 말고 세그먼트 트리를 구성하는 노드 개수

    pair<int, int> InitializeImpl(int currentNode)
    {
        if (currentNode > mNodeCount + mInputCount)
            return { MINIMUM_NOT_FOUND, MAXIMUM_NOT_FOUND };
        if (currentNode > mNodeCount)
            return { mLastLevel[currentNode-mNodeCount-1], mLastLevel[currentNode-mNodeCount-1] };
            
        auto leftValue = InitializeImpl(currentNode << 1);
        auto rightValue = InitializeImpl((currentNode << 1) + 1);
        return mNodes[currentNode] = make_pair(min(leftValue.first, rightValue.first), max(leftValue.second, rightValue.second));
    }

    int GetMinimumInRangeImpl(int currentNode, int currentBegin, int currentEnd, int a, int b)
    {
        if (currentBegin > b || currentEnd < a)
            return MINIMUM_NOT_FOUND;

        if (currentBegin >= a && currentEnd <= b)
        {
            if (currentNode > mNodeCount)
                return mLastLevel[currentNode-mNodeCount-1];
            else
                return mNodes[currentNode].first;
        }
        else if (currentNode > mNodeCount)
            return mLastLevel[currentNode-mNodeCount-1];

        int mid = currentBegin + ((currentEnd-currentBegin) >> 1);
        auto leftValue = MINIMUM_NOT_FOUND;
        auto rightValue = MINIMUM_NOT_FOUND;
        if (mid >= a)
            leftValue = GetMinimumInRangeImpl(currentNode << 1, currentBegin, mid, a, b);
        if (b >= mid)
            rightValue = GetMinimumInRangeImpl((currentNode << 1)+1, mid+1, currentEnd, a, b);
        return min(leftValue, rightValue);
    }

    int GetMaximumInRangeImpl(int currentNode, int currentBegin, int currentEnd, int a, int b)
    {
        if (currentBegin > b || currentEnd < a)
            return MAXIMUM_NOT_FOUND;

        if (currentBegin >= a && currentEnd <= b)
        {
            if (currentNode > mNodeCount)
                return mLastLevel[currentNode-mNodeCount-1];
            else
                return mNodes[currentNode].second;
        }
        else if (currentNode > mNodeCount)
            return mLastLevel[currentNode-mNodeCount-1];

        int mid = currentBegin + ((currentEnd-currentBegin) >> 1);

        auto leftValue = MAXIMUM_NOT_FOUND;
        auto rightValue = MAXIMUM_NOT_FOUND;

        if (mid >= a)
            leftValue = GetMaximumInRangeImpl(currentNode << 1, currentBegin, mid, a, b);
        if (b >= mid)
            rightValue = GetMaximumInRangeImpl((currentNode << 1)+1, mid+1, currentEnd, a, b);
        return max(leftValue, rightValue);
    }

public:
    MinMaxTree() : mInputCount(0), mLastLevel(new int[100001]), mNodes(new pair<int, int>[1000001]) {}
    ~MinMaxTree() 
    {
        delete[] mLastLevel;
        delete[] mNodes;
    }

    void Insert(int num)
    {
        mLastLevel[mInputCount++] = num;
    }

    void Initialize()
    {
        mNodeCount = (1 << static_cast<int>(ceil(log(mInputCount)/log(2)))) - 1;
        InitializeImpl(1);
    }

    int GetMinimumInRange(int a, int b)
    {
        return GetMinimumInRangeImpl(1, 0, mNodeCount, a-1, b-1);
    }

    int GetMaximumInRange(int a, int b)
    {
        return GetMaximumInRangeImpl(1, 0, mNodeCount, a-1, b-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    MinMaxTree minMaxTree;

    for (int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        minMaxTree.Insert(num);
    }
    minMaxTree.Initialize();

    for (int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << minMaxTree.GetMinimumInRange(a, b) << " " << minMaxTree.GetMaximumInRange(a, b) << "\n";
    }
    return 0;
}