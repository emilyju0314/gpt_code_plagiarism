#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Store the sets
    unordered_map<int, vector<int>> sets;
    for (int i = 1; i <= m; ++i) {
        int size;
        cin >> size;
        vector<int> indices(size);
        for (int j = 0; j < size; ++j) {
            cin >> indices[j];
        }
        sets[i] = indices;
    }

    // Process queries
    for (int i = 0; i < q; ++i) {
        char type;
        int k;
        cin >> type >> k;

        if (type == '?') {
            // Find the sum of elements with indices from set Sk
            long long sum = 0;
            for (int index : sets[k]) {
                sum += a[index - 1];
            }
            cout << sum << endl;
        } else if (type == '+') {
            int x;
            cin >> x;
            // Add number x to all elements at indices from set Sk
            for (int index : sets[k]) {
                a[index - 1] += x;
            }
        }
    }

    return 0;
}