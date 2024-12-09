#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int totalMinutes = 240 - k;
    int problemsSolved = 0;
    int timeNeeded = 0;

    for (int i = 1; i <= n; i++) {
        timeNeeded += 5 * i;
        if (timeNeeded <= totalMinutes) {
            problemsSolved++;
        } else {
            break;
        }
    }

    cout << problemsSolved << endl;

    return 0;
}