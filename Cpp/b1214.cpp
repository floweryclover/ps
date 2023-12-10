#include <iostream>

using namespace std;

int main() {
    int D, P, Q;
    cin >> D >> P >> Q;

    int larger = max(P, Q);
    int smaller = min(P, Q);
    int count = D / max(P, Q) + 1;

    int minimum = larger * count;
    for (int i=count-1; i>=0; --i) {
        int current = (larger * i);

        if ((D - current) % smaller == 0) {
            cout << D << endl;
            return 0;
        }

        current += ((D-current)/smaller + 1) * smaller;
        if (minimum == current) break;
        minimum = min(minimum, current);
    }

    cout << minimum << endl;

    return 0;
}