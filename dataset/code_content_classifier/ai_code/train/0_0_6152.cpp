#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> schedule(n);
    for (int i = 0; i < n; i++) {
        cin >> schedule[i];
    }

    int maxRestHours = 0;
    int currentRestHours = 0;

    for (int i = 0; i < 2*n; i++) {
        if (schedule[i % n] == 1) {
            currentRestHours++;
            maxRestHours = max(maxRestHours, currentRestHours);
        } else {
            currentRestHours = 0;
        }
    }

    cout << maxRestHours << endl;

    return 0;
}