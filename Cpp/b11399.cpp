#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n;
    priority_queue<unsigned short, vector<unsigned short>, greater<unsigned short>> p;
    cin >> n;



    for (int i=0; i<n; i++)
    {
        unsigned short input;
        cin >> input;
        p.push(input);
    }

    int elapsed = 0;
    int sum = 0;

    while (!p.empty())
    {
        

        const unsigned short& current = p.top();
        elapsed += current;
        sum += elapsed;
        p.pop();
    }

    cout << sum << endl;
}