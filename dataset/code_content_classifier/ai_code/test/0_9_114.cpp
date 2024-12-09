#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> findPairs(vector<int>& arr) {
    vector<pair<int, int>> pairs;

    unordered_set<int> elements(arr.begin(), arr.end());

    for (int i=0; i<arr.size(); i++) {
        for (int j=i+1; j<arr.size(); j++) {
            int x = arr[i];
            int y = arr[j];
            if (elements.find(x % y) == elements.end() && elements.find(y % x) == elements.end()) {
                pairs.push_back(make_pair(x, y));
            }
        }
    }

    return pairs;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }

        vector<pair<int, int>> pairs = findPairs(arr);

        for (auto p : pairs) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}