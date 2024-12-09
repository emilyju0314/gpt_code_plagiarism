#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> segments(n);
        for (int j = 0; j < n; j++) {
            cin >> segments[j];
        }

        int coverage = segments[0]; // Initialize coverage length with the first segment

        for (int j = 1; j < n; j++) {
            coverage = max(coverage + segments[j], segments[j]); // Calculate new coverage length
        }

        cout << coverage << endl;
    }

    return 0;
}