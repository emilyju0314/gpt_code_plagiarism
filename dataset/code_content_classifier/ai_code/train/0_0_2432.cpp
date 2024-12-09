#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> respectLevels(n);
    for (int i = 0; i < n; i++) {
        cin >> respectLevels[i];
    }

    vector<int> secondsNeeded(n);

    for (int i = 0; i < n; i++) {
        int r_i = respectLevels[i];
        int seconds = 1;
        int left = i - 1;
        int right = i + 1;

        while (left >= 0 && respectLevels[left] <= r_i) {
            seconds++;
            left--;
        }

        while (right < n && respectLevels[right] <= r_i) {
            seconds++;
            right++;
        }

        secondsNeeded[i] = seconds;
    }

    for (int i = 0; i < n; i++) {
        cout << secondsNeeded[i] << " ";
    }

    return 0;
}