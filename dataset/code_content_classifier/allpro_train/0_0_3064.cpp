#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    int min_power = INT_MAX;
    int starting_task = 1;

    for (int i = 0; i < k; i++) {
        int total_power = 0;
        for (int j = i; j < n; j += k) {
            total_power += powers[j];
        }

        if (total_power < min_power) {
            min_power = total_power;
            starting_task = i + 1;
        }
    }

    cout << starting_task << endl;

    return 0;
}