#include <iostream>
#include <queue>

using namespace std;

// () + () + () + () + (), ()의 개수 = N-1
int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        minHeap.push(input);
    }

    int sum = 0;
    while (minHeap.size() > 1)
    {
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        sum += a+b;

        minHeap.push(a+b);
    }

    cout << sum << endl;
}