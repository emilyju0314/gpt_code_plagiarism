#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Number of criminals

    int a, b, c;
    cin >> a >> b >> c; // Strengths of musketeers

    vector<int> criminals(n);
    for (int i = 0; i < n; i++) {
        cin >> criminals[i]; // Strength of each criminal
    }

    sort(criminals.begin(), criminals.end()); // Sort criminals' strengths

    int min_hours = -1;

    for (int i = 0; i < n; i++) {
        int idx = upper_bound(criminals.begin(), criminals.end(), criminals[i] - a) - criminals.begin();
        int jdx = upper_bound(criminals.begin(), criminals.end(), criminals[i] - a - b) - criminals.begin();

        if (idx < n && jdx < n && criminals[idx] <= a && criminals[jdx] <= a + b) {
            min_hours = i / 3 + 1;
            break;
        }
    }

    cout << min_hours << endl;

    return 0;
}