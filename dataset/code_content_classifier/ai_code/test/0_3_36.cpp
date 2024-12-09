#include <iostream>
#include <vector>

using namespace std;

bool isComposite(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
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

        for (int k = n; k >= 1; k--) {
            for (int i = 0; i <= n - k; i++) {
                int sum = 0;
                for (int j = i; j < i + k; j++) {
                    sum += arr[j];
                }
                if (isComposite(sum)) {
                    cout << k << endl;
                    for (int j = i; j < i + k; j++) {
                        cout << j + 1 << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}