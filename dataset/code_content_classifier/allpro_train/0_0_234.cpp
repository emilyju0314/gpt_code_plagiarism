#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    // Check if it's possible to visit all oases from each starting point
    for (int i = 0; i < N; i++) {
        bool possible = true;

        // Check if it's possible to reach the next oasis from the current one
        for (int j = 1; j < N; j++) {
            int diff = abs(x[j] - x[j - 1]);
            if (diff > V) {
                possible = false;
                break;
            }
            V -= (diff < V) ? diff : V;
        }

        cout << (possible ? "Possible" : "Impossible") << endl;
    }

    return 0;
}