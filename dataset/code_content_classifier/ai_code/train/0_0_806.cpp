#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string left, right;
    cin >> left >> right;

    bool canEscape = false;
    for (int i = 0; i < n; i++) {
        if (left[i] == 'X' && right[i] == '-') {
            int diff = i % k;
            if (diff == 0) {
                canEscape = true;
                break;
            }
        } else if (left[i] == '-' && right[i] == 'X') {
            int diff = k - (i % k);
            if (diff <= n) {
                canEscape = true;
                break;
            }
        }
    }

    if (canEscape) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}