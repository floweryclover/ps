#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long int t, n, m;
    cin >> t;
    array<array<unsigned long long, 31>, 31> pascal;
    for (int i=0; i<=30; i++)
    {
        pascal[i][0] = 1;
        for (int j=1; j<i; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            
        pascal[i][i] = 1;
    }
    for (int i=0; i<t; i++)
    {
        cin >> n;
        cin >> m;
        
        cout << pascal[m][n] << "\n";
    }
}