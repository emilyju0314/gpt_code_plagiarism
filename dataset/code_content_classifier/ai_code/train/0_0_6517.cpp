#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string initial_state;
        cin >> initial_state;

        string current_state = initial_state;

        for (int i = 0; i < m; i++) {
            string next_state = current_state;
            for (int j = 0; j < n; j++) {
                int alive_neighbors = 0;
                if (j > 0 && current_state[j-1] == '1') alive_neighbors++;
                if (j < n-1 && current_state[j+1] == '1') alive_neighbors++;

                if (current_state[j] == '0' && alive_neighbors == 1) {
                    next_state[j] = '1';
                }
            }
            current_state = next_state;
        }

        cout << current_state << endl;
    }

    return 0;
}