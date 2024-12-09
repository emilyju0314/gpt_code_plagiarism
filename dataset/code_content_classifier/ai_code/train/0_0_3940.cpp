#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, C;
    cin >> N >> K >> C;

    vector<int> holidays(C);
    for (int i = 0; i < C; i++) {
        cin >> holidays[i];
    }

    int presents = 0;
    int daysUntilNextPresent = 0;

    for (int day = 1; day <= N; day++) {
        if (daysUntilNextPresent == 0 || find(holidays.begin(), holidays.end(), day) != holidays.end()) {
            presents++;
            daysUntilNextPresent = K;
        } else {
            daysUntilNextPresent--;
        }
    }

    cout << presents << endl;

    return 0;
}