#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_changes(string a, string b) {
    int changes = 0;
    for (int i = 0; i < b.length(); i++) {
        if (a[i] != b[i]) {
            changes++;
        }
    }
    return changes;
}

int main() {
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<int> results(n - m + 2, -1);

    for (int k = 0; k <= n - m + 1; k++) {
        int total_changes = 0;
        for (int i = 0; i < a.length() - m + 1; i++) {
            string substr = a.substr(i, m);
            int changes = count_changes(substr, b);
            if (changes == k) {
                total_changes++;
            }
        }
        results[k] = n - m + 1 - total_changes;
    }

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }

    return 0;
}