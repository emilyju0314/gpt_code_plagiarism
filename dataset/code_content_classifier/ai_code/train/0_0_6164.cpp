#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        unordered_map<int, pair<int, int>> zeros; // to store the position of 0s

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                zeros[i] = make_pair(-1, -1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                if (!zeros.empty()) {
                    auto it = zeros.begin();
                    pair<int, int> first_zero = it->second;
                    zeros.erase(it);

                    if (first_zero.first == -1) {
                        first_zero.first = i;
                    } else {
                        first_zero.second = i;
                    }

                    zeros[i] = first_zero;
                }
            }
        }

        cout << zeros.size() << endl;
    }

    return 0;
}