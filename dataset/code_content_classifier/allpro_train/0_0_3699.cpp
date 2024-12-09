#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> desired_counts(m);

    for (int i = 0; i < m; i++) {
        cin >> desired_counts[i];
    }

    vector<int> counts(m);
    int start = 0, end = 0;
    int removed = 0, min_removed = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        counts[colors[i] - 1]++;
        
        while (end < n && !isValid(counts, desired_counts)) {
            counts[colors[end] - 1]--;
            end++;
        }

        if (isValid(counts, desired_counts)) {
            min_removed = min(min_removed, removed);
        }

        counts[colors[start] - 1]--;
        start++;
    }

    if (min_removed == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_removed << endl;
    }

    return 0;
}