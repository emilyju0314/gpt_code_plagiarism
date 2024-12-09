#include <iostream>
#include <vector>

using namespace std;

bool canEraseSequence(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % (i + 1) != 0) {
            return true;
        }
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

        if (canEraseSequence(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}