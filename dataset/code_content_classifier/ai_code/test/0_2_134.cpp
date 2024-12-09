#include <iostream>
#include <vector>

using namespace std;

bool isBeautiful(vector<int>& arr, int d) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] % d == 0 && arr[i + 1] % d == 0) {
            return false;
        }
    }
    return true;
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

        int d = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] % arr[0] != 0) {
                d = arr[0];
                break;
            }
        }

        if (d == 0) {
            cout << 0 << endl;
        } else {
            cout << d << endl;
        }
    }

    return 0;
}