#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    // Loop through each test case
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, int> first_occurrence, last_occurrence;

        for (int j = 0; j < n; j++) {
            cin >> a[j];
            last_occurrence[a[j]] = j;
            if (first_occurrence.find(a[j]) == first_occurrence.end()) {
                first_occurrence[a[j]] = j;
            }
        }

        int max_length = 0;

        for (auto it = first_occurrence.begin(); it != first_occurrence.end(); it++) {
            int key = it->first;
            int start = it->second;
            int end = last_occurrence[key];

            int count = end - start + 1;
            count += 2 * (end - max(end, first_occurrence[key] + 1) + 1);

            max_length = max(max_length, min(count, n));
        }

        cout << max_length << endl;
    }

    return 0;
}