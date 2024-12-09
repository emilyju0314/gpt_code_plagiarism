#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m, t;
    cin >> n >> k >> m >> t;

    // Initialize the multiverse with n universes and the Doctor in the k-th universe
    vector<int> multiverse(n, 0);
    multiverse[k-1] = 1;

    for (int i = 0; i < t; i++) {
        int op, pos;
        cin >> op >> pos;

        if (op == 0) {
            // Break link at position pos
            multiverse[pos-1] = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (multiverse[j] == 1) {
                    count++;
                }
            }
            n = count;
        } else {
            // Insert universe at position pos
            multiverse.insert(multiverse.begin() + pos - 1, 1);
            n = multiverse.size();
        }

        // Update the position of the Doctor
        k = 0;
        for (int j = 0; j < n; j++) {
            if (multiverse[j] == 1) {
                k = j + 1;
                break;
            }
        }

        // Output the current length of the multiverse and the position of the Doctor
        cout << n << " " << k << endl;
    }

    return 0;
}