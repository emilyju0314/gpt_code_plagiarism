#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<bool> visited(n, false);
    int changes = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cycle_size = 1;
            int current = i;
            while (p[current] != i) {
                current = p[current];
                visited[current] = true;
                cycle_size++;
            }

            if (cycle_size == 1) {
                changes++;
            } else if (!b[i]) {
                changes++;
            }
        }
    }

    cout << changes << endl;

    return 0;
}