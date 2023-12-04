#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <regex>

using namespace std;

class Compare {
private:
    unsigned short OrderOf(char ch) {
        switch (ch) {
            case 'a': return 0;
            case 'b': return 1;
            case 'k': return 2;
            case 'd': return 3;
            case 'e': return 4;
            case 'g': return 5;
            case 'h': return 6;
            case 'i': return 7;
            case 'l': return 8;
            case 'm': return 9;
            case 'n': return 10;
            case 'Z': return 11;
            case 'o': return 12;
            case 'p': return 13;
            case 'r': return 14;
            case 's': return 15;
            case 't': return 16;
            case 'u': return 17;
            case 'w': return 18;
            case 'y': return 19;
        }

        return -1;
    }

public:
    bool operator()(const string& a, const string& b) {
        auto aIter = a.begin();
        auto bIter = b.begin();
        while (aIter != a.end() &&  bIter != b.end()) {
            if (OrderOf(*aIter) != OrderOf(*bIter))
                return OrderOf(*aIter) < OrderOf(*bIter);

            aIter++;
            bIter++;
        }

        return aIter == a.end();
    }
};

int main() {
    int N;
    cin >> N;
    
    array<string, 50> inputs;
    for (int i=0; i<N; i++) {
        string input;
        cin >> input;
        inputs[i] = regex_replace(input, regex("ng"), "Z");
    }

    sort(inputs.begin(), inputs.begin() + N, Compare());

    for (int i=0; i<N; i++) {
        cout << regex_replace(inputs[i], regex("Z"), "ng") << endl;
    }
}