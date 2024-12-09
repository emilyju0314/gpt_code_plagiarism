#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // Count the number of removals needed
    int removals = 0;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(sequence.begin(), sequence.end());

    for (int i = 0; i < n; i++) {
        int min_xor = 1e9;
        int min_j = -1;

        for (int j = i+1; j < n; j++) {
            if ((sequence[i] ^ sequence[j]) < min_xor) {
                min_xor = sequence[i] ^ sequence[j];
                min_j = j;
            }
        }

        if (parent[i] != parent[min_j]) {
            parent[min_j] = parent[i];
        } else {
            removals++;
        }
    }

    cout << removals << endl;

    return 0;
}