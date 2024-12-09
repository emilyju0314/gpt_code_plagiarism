#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> cards(m);
    for (int i = 0; i < m; i++) {
        cin >> cards[i];
    }

    int maxLength = 1;
    int maxLengthIndex = 0;
    int currentLength = 1;

    for (int i = 1; i < m; i++) {
        if (cards[i] > cards[i - 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxLengthIndex = i - currentLength;
            }
            currentLength = 1;
        }
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
        maxLengthIndex = m - currentLength;
    }

    cout << maxLength << endl;

    for (int i = maxLengthIndex; i < maxLengthIndex + maxLength - 1; i++) {
        cout << cards[i] << " ";
    }
    cout << cards[maxLengthIndex + maxLength - 1] << endl;

    return 0;
}