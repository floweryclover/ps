#include <iostream>
#include <array>

using namespace std;

int Sequence(int N, int row, array<array<bool, 15>, 15> table) {
    if (row==N) return 1;

    int sum = 0;
    for (int col=0; col<N; col++) {
        if (!table[row][col]) continue;

        array<array<bool, 15>, 15> new_table = table;
        for (int i=row+1; i<N; i++) {
            if (col-(i-row) >= 0) new_table[i][col-(i-row)] = false;
            if (col+(i-row) < N) new_table[i][col+(i-row)] = false;
            new_table[i][col] = false;
        }

        sum += Sequence(N, row+1, new_table);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;


    array<array<bool, 15>, 15> table;
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            table[i][j] = true;
        }
    }

    cout << Sequence(N, 0, table) << endl;
    return 0;
}