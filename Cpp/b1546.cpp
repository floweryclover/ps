#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int maximum = 0;
    array<int, 1000> inputs;
    for (int i=0; i<n; i++)
    {
        cin >> inputs[i];
        maximum = max(maximum, inputs[i]);
    }

    double ratio = 100.0/maximum/n;
    double average = 0.0;
    for (int i=0; i<n; i++)
    {
        average += inputs[i] * ratio; 
    }
    
    cout << average << endl;
    return 0;
}