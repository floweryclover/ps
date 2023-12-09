#include <iostream>
#include <array>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    array<array<int, 8>, 8> lab;
    array<pair<int, int>, 10> virus;
    int virusCount = 0;
    int safeCount = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int input;
            cin >> input;
            lab[i][j] = input;
            if (input == 2) virus[virusCount++] = {i, j};
            else if (input == 0) safeCount++;
        }
    }

    int maxSafeCount = 0;
    for (int i=0; i<N*M-2; i++) {
        if (lab[i/M][i%M] != 0) continue;
        array<int, 3> walls;
        walls[0] = i;
        for (int j=i+1; j<N*M-1; j++) {
            if (lab[j/M][j%M] != 0) continue;
            walls[1] = j;
            for (int k=j+1; k<N*M; k++) {
                if (lab[k/M][k%M] != 0) continue;
                walls[2] = k;
                array<array<int, 8>, 8> labCopy = lab;

                for (const auto& wall : walls) {
                    int y = wall / M;
                    int x = wall % M;
                    
                    labCopy[y][x] = 1;
                }

                array<array<bool, 8>, 8> visited;
                for (int y=0; y<8; y++) {
                    for (int x=0; x<8; x++) {
                        visited[y][x] = false;
                    }
                }
                int currentSafeCount = safeCount - 3;
                for (int v=0; v<virusCount; v++) {
                    queue<pair<int, int>> search;
                    search.push(virus[v]);

                    while (!search.empty()) {
                        auto current = search.front();
                        search.pop();

                        int y = current.first;
                        int x = current.second;

                        if (visited[y][x]) continue;

                        if (labCopy[y][x] == 0) currentSafeCount--;

                        visited[y][x] = true;
                        if (y>0 && labCopy[y-1][x] == 0 && visited[y-1][x] == false) search.push({ y-1, x });
                        if (y<N-1 && labCopy[y+1][x] == 0 && visited[y+1][x] == false) search.push({ y+1, x });
                        if (x>0 && labCopy[y][x-1] == 0 && visited[y][x-1] == false) search.push({ y, x-1 });
                        if (x<M-1 && labCopy[y][x+1] == 0 && visited[y][x+1] == false) search.push({ y, x+1 });
                    }
                }
                
                if (currentSafeCount > maxSafeCount) {
                    maxSafeCount = currentSafeCount;
                }
            }
        }
    }

    cout << maxSafeCount << endl;
    return 0;
}