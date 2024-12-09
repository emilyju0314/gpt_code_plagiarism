#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cups(n);
    for (int i = 0; i < n; i++) {
        cin >> cups[i];
    }

    int initialSum = 0;
    for (int i = 0; i < n; i++) {
        initialSum += cups[i];
    }

    int sourceCup = -1;
    int destCup = -1;
    int pouredVolume = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int sum1 = initialSum - cups[i];
                int sum2 = initialSum - cups[j];

                if (sum1 == sum2) {
                    pouredVolume = cups[i] - sum1;
                    sourceCup = i + 1;
                    destCup = j + 1;
                }
            }
        }
    }

    if (sourceCup == -1) {
        int sum = initialSum / n;
        bool exemplary = true;

        for (int i = 0; i < n; i++) {
            if (cups[i] != sum) {
                exemplary = false;
                break;
            }
        }

        if (exemplary) {
            cout << "Exemplary pages." << endl;
        } else {
            cout << "Unrecoverable configuration." << endl;
        }
    } else {
        cout << pouredVolume << " ml. from cup #" << sourceCup << " to cup #" << destCup << "." << endl;
    }

    return 0;
}