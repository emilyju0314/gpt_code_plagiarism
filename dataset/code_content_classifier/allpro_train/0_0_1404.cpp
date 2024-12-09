#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += boxes[i];
    }

    int minSeconds = -1;
    for (int k = 2; k <= totalSum; k++) {
        if (totalSum % k == 0) {
            int seconds = 0;
            int count = 0;
            for (int i = 0; i < n; i++) {
                while (boxes[i] % k != 0) {
                    boxes[i]++;
                    seconds++;
                }
                count += boxes[i] / k;
            }

            if (count == totalSum / k) {
                if (minSeconds == -1) {
                    minSeconds = seconds;
                } else {
                    minSeconds = min(minSeconds, seconds);
                }
            }
        }
    }

    cout << minSeconds << endl;

    return 0;
}