#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> house(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    int answer = 0;
    int last_heater = -1;

    for (int i = 0; i < n; i++) {
        // If the current element is not warmed up
        if (house[i] == 0) {
            bool found_heater = false;

            // Search for a heater that can warm up the current element
            for (int j = max(0, i - r + 1); j < min(n, i + r); j++) {
                if (house[j] == 1) {
                    found_heater = true;
                    last_heater = j;
                    answer++;
                    break;
                }
            }

            // If no heater can warm up the current element, it is impossible to warm up the whole house
            if (!found_heater) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << answer << endl;

    return 0;
}