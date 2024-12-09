#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> workTimes(n);
    for (int i = 0; i < n; i++) {
        cin >> workTimes[i];
    }

    int day = 1;
    int timeLeft = 0;
    for (int i = 0; i < n; i++) {
        timeLeft += 86400 - workTimes[i];
        if (timeLeft >= t) {
            break;
        } else {
            day++;
        }
    }

    cout << day << endl;

    return 0;
}