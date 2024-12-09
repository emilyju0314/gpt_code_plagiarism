#include <iostream>
#include <vector>

using namespace std;

int determineResult(int hand1, int hand2) {
    if (hand1 == hand2) {
        return 3; // Aiko
    } else if ((hand1 == 1 && hand2 == 2) || (hand1 == 2 && hand2 == 3) || (hand1 == 3 && hand2 == 1)) {
        return 1; // Win
    } else {
        return 2; // Lose
    }
}

int main() {
    int h1, h2, h3, h4, h5;

    while (true) {
        cin >> h1;
        if (h1 == 0) {
            break;
        }

        cin >> h2 >> h3 >> h4 >> h5;

        vector<int> hands = {h1, h2, h3, h4, h5};

        for (int i = 0; i < 5; i++) {
            int result = determineResult(hands[i], hands[(i + 1) % 5]);
            cout << result << endl;
        }
    }

    return 0;
}