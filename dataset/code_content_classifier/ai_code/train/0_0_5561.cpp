#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    bool canWin = true;
    bool canLose = true;
    long long maxVal = 1;

    for (int i = 0; i < t; i++) {
        long long s, e;
        cin >> s >> e;

        while (maxVal < e) {
            if (maxVal % 2 == 0) {
                maxVal = 2 * maxVal;
            } else {
                maxVal = 2 * maxVal + 1;
            }
        }

        if (maxVal <= e) {
            canLose = false;
        } else {
            canWin = false;
        }

        maxVal = max(2 * s, maxVal);
    }

    cout << canWin << " " << canLose << endl;

    return 0;
}