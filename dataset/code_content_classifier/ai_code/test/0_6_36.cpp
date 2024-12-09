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

        for (int i = n; i >= 3; i--) {
            for (int j = 0; j <= n - i; j++) {
                int sum = 0;
                vector<int> subset;
                for (int k = j; k < j + i; k++) {
                    sum += arr[k];
                    subset.push_back(k + 1);
                }
                if (isComposite(sum)) {
                    cout << i << endl;
                    for (int num : subset) {
                        cout << num << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}