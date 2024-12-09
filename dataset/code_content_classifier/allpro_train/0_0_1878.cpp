#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    long long totalArrows = 0;
    for (int i = 0; i < q; i++) {
        long long arrows;
        cin >> arrows;

        totalArrows += arrows;

        int remainingWarriors = n;
        int lastWarrior = 0;
        for (int j = 0; j < n; j++) {
            if (arrows >= strengths[j]) {
                arrows -= strengths[j];
                remainingWarriors--;
            } else {
                lastWarrior = j + 1;
                break;
            }
        }

        if (remainingWarriors == 0) {
            totalArrows -= arrows;
            cout << n << endl;
        } else {
            if (lastWarrior != 1) totalArrows -= strengths[lastWarrior - 1];
            cout << remainingWarriors << endl;
        }
    }

    return 0;
}