#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    array<int, 500> selection;
    array<int, 500> current;
    array<int, 500> prev;
    int n;
    cin >> n;
    prev[0] = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i-1; j++)
            prev[j] = selection[j];

        for (int j=0; j<=i; j++)
            cin >> current[j];
            

        selection[0] = prev[0] + current[0];

        for (int j=1; j<=i-1; j++)
            selection[j] = max(prev[j], prev[j-1]) + current[j];

        selection[i] = prev[i-1] + current[i];
    }

    int maximum = 0;
    for (int i=0; i<n; i++)
        maximum = max(maximum, selection[i]);

    cout << maximum << endl;
    return 0;
}