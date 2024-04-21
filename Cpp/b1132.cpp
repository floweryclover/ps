#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

struct RankData
{
    bool mIsUndefined;
    bool mIsNonzero;
    char mAlphabet;
    unsigned long long mRank;
    RankData() : mIsUndefined(true), mRank(0), mIsNonzero(false) {}

    void AddRank(unsigned long long value)
    {
        mIsUndefined = false;
        mRank += value;
    }

    bool IsUndefined()
    {
        return mIsUndefined;
    }

    bool operator<(const RankData& rhs) const
    {
        if (mIsUndefined && rhs.mIsUndefined)
            return true;
        else if (mIsUndefined || rhs.mIsUndefined)
            return mIsUndefined == false;
        
        if (mRank == rhs.mRank)
            return mAlphabet > rhs.mAlphabet;
        else
            return mRank > rhs.mRank;
    }

    void SetNonzero()
    {
        mIsNonzero = true;
    }

    bool IsNonzero()
    {
        return mIsNonzero;
    }
};

unsigned long long Parse(const array<int, 10>& assignedNumbers, const string& stringNumber)
{
    unsigned long long sum = 0;
    for (char ch : stringNumber)
    {
        sum *= 10;
        sum += assignedNumbers[ch - 'A'];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 50> inputs;
    array<RankData, 10> rankDatas;
    for (int i=0; i<10; i++)
        rankDatas[i].mAlphabet = 'A' + i;

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> inputs[i];
        const string& input = inputs[i];

        unsigned long long power = 1;
        for (int j=input.length()-1; j>=0; --j)
        {
            char ch = input[j];
            rankDatas[ch - 'A'].AddRank(power);
            power *= 10;
        }

        rankDatas[input[0] - 'A'].SetNonzero();
    }

    sort(rankDatas.begin(), rankDatas.end());

    if (!rankDatas[9].IsUndefined() && rankDatas[9].IsNonzero())
    {
        auto zero = rankDatas.rend();
        for (auto iter = rankDatas.rbegin()+1; iter != rankDatas.rend(); iter++)
        {
            if (!iter->IsNonzero())
            {
                zero = iter;
                break;
            }
        }

        zero->mRank = 0;
        sort(rankDatas.begin(), rankDatas.end());
    }

    array<int, 10> assignedNumbers;
    for (int num = 9; num >= 0; --num)
    {
        if (rankDatas[9-num].IsUndefined())
            break;

        assignedNumbers[rankDatas[9-num].mAlphabet - 'A'] = num;
    }

    unsigned long long sum = 0;
    for (int i=0; i<n; i++)
        sum += Parse(assignedNumbers, inputs[i]);

    cout << sum << endl;

    return 0;
}