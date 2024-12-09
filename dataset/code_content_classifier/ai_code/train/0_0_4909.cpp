#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    // Find the days on which Takahashi is bound to work
    vector<int> workDays;
    int l = 0, r = N - 1;
    int workDaysCount = 0;
    while (workDaysCount < K) {
        for (int i = l; i <= r; i++) {
            if (S[i] == 'o') {
                workDays.push_back(i + 1);
                workDaysCount++;
                l = i + C + 1;
                break;
            }
        }
        r = N - 1;
    }

    // Output the work days in ascending order
    for (int i = 0; i < workDays.size(); i++) {
        cout << workDays[i] << endl;
    }

    return 0;
}