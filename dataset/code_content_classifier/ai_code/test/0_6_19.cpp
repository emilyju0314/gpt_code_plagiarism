#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> segments(n);
        for (int i = 0; i < n; i++) {
            cin >> segments[i];
        }

        int total_length = segments[0];
        int current_end = 0;

        for (int i = 1; i < n; i++) {
            if (segments[i] > segments[i-1]) {
                total_length += segments[i] - segments[i-1];
            } else {
                total_length += segments[i] - segments[i-1];
            }
        }

        cout << total_length << endl;
    }

    return 0;
}