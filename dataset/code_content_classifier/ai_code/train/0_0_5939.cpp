#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n); // original sequence
    unordered_map<int, int> index; // mapping from element value to its index in the vector

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        index[a[i]] = i;
    }

    sort(a.begin(), a.end()); // sort the original sequence

    vector<vector<int>> subsequences;
    vector<bool> taken(n, false);

    for (int i = 0; i < n; i++) {
        if (taken[i]) continue;

        vector<int> subsequence;
        int j = i;

        while (!taken[j]) {
            subsequence.push_back(index[a[j]] + 1);
            taken[j] = true;
            j = index[a[j]];
        }

        subsequences.push_back(subsequence);
    }

    cout << subsequences.size() << endl;
    for (auto subsequence : subsequences) {
        cout << subsequence.size() << " ";
        for (int element : subsequence) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}