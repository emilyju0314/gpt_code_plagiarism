#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<string> schedule(d);
    for (int i = 0; i < d; i++) {
        cin >> schedule[i];
    }

    int max_consecutive_days = 0;
    int consecutive_days = 0;

    for (int i = 0; i < d; i++) {
        bool all_present = true;
        for (int j = 0; j < n; j++) {
            if (schedule[i][j] == '0') {
                all_present = false;
                break;
            }
        }

        if (all_present) {
            consecutive_days++;
            max_consecutive_days = max(max_consecutive_days, consecutive_days);
        } else {
            consecutive_days = 0;
        }
    }

    cout << max_consecutive_days << endl;

    return 0;
}