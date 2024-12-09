#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> counts;
    int prefix_xor = 0;
    int funny_pairs = 0;
    counts[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix_xor ^= a[i];
        if (i % 2 == 1) {
            counts[prefix_xor]++;
        }
        funny_pairs += counts[prefix_xor] - 1; // Subtract 1 to exclude the current element
    }

    cout << funny_pairs << endl;

    return 0;
}