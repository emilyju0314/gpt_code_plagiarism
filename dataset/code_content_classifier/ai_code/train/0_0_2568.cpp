#include <iostream>
#include <algorithm>

using namespace std;

int charToInt(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return c - 'a' + 10;
    }
}

char intToChar(int n) {
    if (n < 10) {
        return '0' + n;
    } else {
        return 'a' + n - 10;
    }
}

int main() {
    string diff;
    cin >> diff;

    int len = diff.length();
    string original = diff;
    string sortedDiff = diff;

    sort(sortedDiff.begin(), sortedDiff.end());

    if (sortedDiff == original) {
        cout << "NO" << endl;
    } else {
        reverse(sortedDiff.begin(), sortedDiff.end());

        for (int i = 0; i < len; i++) {
            int diffVal = charToInt(diff[i]);
            int sortVal = charToInt(sortedDiff[i]);

            if (diffVal < sortVal) {
                original[i] = intToChar(diffVal);
            } else if (diffVal > sortVal) {
                original[i] = intToChar(sortVal);
            }
        }

        cout << original << endl;
    }

    return 0;
}