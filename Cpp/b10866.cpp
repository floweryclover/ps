#include <iostream>
#include <array>

using namespace std;

class Deque
{
private:
    array<int, 20001> mData;
    int mBackIndex;
    int mFrontIndex;

public:
    Deque() : mBackIndex(10000), mFrontIndex(9999)
    {}

    void PushFront(const int value)
    {
        mData[mFrontIndex--] = value;
    }

    void PushBack(const int value)
    {
        mData[mBackIndex++] = value;
    }

    int IsEmpty()
    {
        return (mBackIndex - mFrontIndex == 1 ? 1 : 0);
    }

    int size()
    {
        return mBackIndex - mFrontIndex - 1;
    }

    int PopFront()
    {
        if (IsEmpty())
            return -1;
        return mData[++mFrontIndex];
    }

    int PopBack()
    {
        if (IsEmpty())
            return -1;
        return mData[--mBackIndex];
    }

    int Front()
    {
        if (IsEmpty())
            return -1;
        return mData[mFrontIndex+1];
    }

    int Back()
    {
        if (IsEmpty())
            return -1;
        return mData[mBackIndex-1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Deque deque;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        if (input == "push_front")
        {
            int x;
            cin >> x;
            deque.PushFront(x);
        }
        else if (input == "push_back")
        {
            int x;
            cin >> x;
            deque.PushBack(x);
        }
        else if (input == "pop_front")
        {
            cout << deque.PopFront() << "\n";
        }
        else if (input == "pop_back")
        {
            cout << deque.PopBack() << "\n";
        }
        else if (input == "size")
        {
            cout << deque.size() << "\n";
        }
        else if (input == "empty")
        {
            cout << deque.IsEmpty() << "\n";
        }
        else if (input == "front")
        {
            cout << deque.Front() << "\n";
        }
        else if (input == "back")
        {
            cout << deque.Back() << "\n";
        }
    }

    return 0;
}