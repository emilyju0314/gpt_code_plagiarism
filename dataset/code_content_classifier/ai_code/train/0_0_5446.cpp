#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }

    sort(health.begin(), health.end(), greater<int>());

    int total = 1; // Start with the initial square
    for (int i = 0; i < n; i++) {
        if (health[i] > i) {
            total += i + 1;
        } else {
            break;
        }
    }

    cout << total << endl;

    return 0;
}