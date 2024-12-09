#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int i, vector<int>& k) {
    for (int j = 0; j < k.size(); j++) {
        if ((k[j] >> i) & 1) {
            if (j == k.size() - 1 || !((k[j + 1] >> i) & 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }

        int max_num = -1, min_num = 1e9;

        for (int i = 0; i < 64; i++) {
            if (isValid(i, k)) {
                min_num = min(min_num, i);
            }
        }

        for (int i = 63; i >= 0; i--) {
            if (isValid(i, k)) {
                max_num = max(max_num, i);
            }
        }

        if (min_num > max_num) {
            cout << "None" << endl;
        } else if (min_num == max_num) {
            cout << min_num << endl;
        } else {
            cout << "Many" << endl;
        }
    }

    return 0;
}