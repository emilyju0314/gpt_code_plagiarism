#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n);
    unordered_set<long long> s;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }

    unordered_set<long long> erased;

    for (int i = 0; i < n; i++) {
        if (erased.count(b[i]) == 0) {
            for (long long j = b[i]; j <= 1e18; j += b[i]) {
                if (s.count(j) == 0 && erased.count(j) == 0) {
                    erased.insert(b[i]);
                    break;
                }
            }
        }
    }

    cout << erased.size() << endl;
    for (auto num : erased) {
        cout << num << " ";
    }

    return 0;
}