#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> degrees(n + 1, 0); // Initialize degrees of all vertices to 0

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        degrees[a]++;
        degrees[b]++;
    }

    int leaf_count = 0, degree_one_count = 0;
    for (int i = 1; i <= n; i++) {
        if (degrees[i] == 1) {
            leaf_count++;
        } else if (degrees[i] == n - 1) {
            degree_one_count++;
        } else if (degrees[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    if (leaf_count == n - 1 && degree_one_count == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}