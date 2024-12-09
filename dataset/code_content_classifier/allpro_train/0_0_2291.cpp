#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i];
    }

    int untreatedCrimes = 0;
    int officers = 0;
    for (int i = 0; i < n; i++) {
        if (events[i] == -1) {
            if (officers > 0) {
                officers--;
            } else {
                untreatedCrimes++;
            }
        } else {
            officers += events[i];
        }
    }

    cout << untreatedCrimes << endl;

    return 0;
}