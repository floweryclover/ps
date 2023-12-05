#include <iostream>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    array<array<short, 500>, 500> paper;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    int max = 1;
    { // 긴막대
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M - 3; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
                if (sum > max) max = sum;
            }
        }
        for (int i = 0; i < N - 3; i++) {
            for (int j = 0; j < M; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
                if (sum > max) max = sum;
            }
        }
    }

    { // 정사각형
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];
                if (sum > max) max = sum;
            }
        }
    }

    { // ㄴ
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i][j + 2];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 2];
                if (sum > max) max = sum;
            }
        }
    }

    { // 역방향 ㄴ
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < M-1; j++) {
                int sum = paper[i][j] + paper[i][j+1] + paper[i-1][j+1] + paper[i-2][j+1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < M-2; j++) {
                int sum = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N-2; i++) {
            for (int j = 0; j < M-1; j++) {
                int sum = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+2][j];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < M-2; j++) {
                int sum = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];
                if (sum > max) max = sum;
            }
        }
    }

    { // 4번째 도형
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N - 2; i++) {
            for (int j = 1; j < M; j++) {
                int sum = paper[i][j] + paper[i + 1][j] + paper[i + 1][j-1] + paper[i + 2][j-1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i - 1][j + 1] + paper[i - 1][j + 2];
                if (sum > max) max = sum;
            }
        }

        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i+1][j+1] + paper[i+1][j+2];
                if (sum > max) max = sum;
            }
        }
    }

    { // 5번째 도형
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                int sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i - 1][j + 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 2; i < N; i++) {
            for (int j = 1; j < M; j++) {
                int sum = paper[i][j] + paper[i - 1][j] + paper[i - 2][j] + paper[i - 1][j - 1];
                if (sum > max) max = sum;
            }
        }

        for (int i = 2; i < N; i++) {
            for (int j = 0; j < M - 1; j++) {
                int sum = paper[i][j] + paper[i - 1][j] + paper[i - 2][j] + paper[i - 1][j + 1];
                if (sum > max) max = sum;
            }
        }
    }

    cout << max << endl;
    return 0;
}