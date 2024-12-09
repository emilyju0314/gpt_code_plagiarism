#include <iostream>
#include <string>

using namespace std;

void changeColors(string& chips) {
    int n = chips.length();
    string newChips = chips;

    for (int i = 0; i < n; i++) {
        int whiteCount = 0, blackCount = 0;

        if (i == 0) {
            whiteCount = (chips[n - 1] == 'W') + (chips[i] == 'W') + (chips[i + 1] == 'W');
            blackCount = 3 - whiteCount;
        } else if (i == n - 1) {
            whiteCount = (chips[n - 2] == 'W') + (chips[i] == 'W') + (chips[0] == 'W');
            blackCount = 3 - whiteCount;
        } else {
            whiteCount = (chips[i - 1] == 'W') + (chips[i] == 'W') + (chips[i + 1] == 'W');
            blackCount = 3 - whiteCount;
        }

        if (whiteCount > blackCount) {
            newChips[i] = 'W';
        } else {
            newChips[i] = 'B';
        }
    }

    chips = newChips;
}

int main() {
    int n, k;
    cin >> n >> k;

    string chips;
    cin >> chips;

    while (k > 0) {
        changeColors(chips);
        k--;
    }

    cout << chips << endl;

    return 0;
}