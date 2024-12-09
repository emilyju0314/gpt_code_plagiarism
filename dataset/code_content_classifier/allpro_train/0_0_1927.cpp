#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    int n;
    cin >> n;

    vector<int> melody(n);
    for (int i = 0; i < n; i++) {
        cin >> melody[i];
    }

    sort(a.begin(), a.end());
    sort(melody.begin(), melody.end());

    int minDiff = melody[n-1] - melody[0]; // Initialize with maximum possible difference

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            int curDiff = abs(melody[i] - a[j]);
            minDiff = min(minDiff, curDiff);
        }
    }

    cout << minDiff << endl;

    return 0;
}