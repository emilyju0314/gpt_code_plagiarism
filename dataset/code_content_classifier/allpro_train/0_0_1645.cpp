#include <iostream>
#include <vector>

using namespace std;

int main() {
    int S, T, D;
    cin >> S >> T >> D;

    vector<int> weights(D);
    for (int i = 0; i < D; i++) {
        cin >> weights[i];
    }

    int currentWeight = S;
    int days = 0;

    for (int i = 0; i < D; i++) {
        currentWeight += weights[i];
        days++;
        if (currentWeight <= T) {
            cout << days << endl;
            return 0;
        }
    }

    while (true) {
        currentWeight += weights[days % D];
        days++;
        if (currentWeight <= T) {
            cout << days << endl;
            return 0;
        }
        if (days > 100000) {
            cout << -1 << endl;
            return 0;
        }
    }

    return 0;
}