#include <iostream>
#include <vector>

using namespace std;

bool isComposite(int n) {
    if (n <= 3) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int sum = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (isComposite(sum)) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << 1 << endl;
            cout << 1 << endl;
        } else {
            cout << idx + 1 << endl;
            for (int i = 0; i <= idx; i++) {
                cout << i + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}