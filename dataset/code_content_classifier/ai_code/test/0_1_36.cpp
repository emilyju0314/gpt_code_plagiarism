#include <iostream>
#include <vector>

using namespace std;

bool isComposite(int num) {
    if (num < 4) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return true;
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

        int sum = 0;
        vector<int> indices;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (isComposite(sum)) {
                cout << i + 1 << endl;
                for (int j = 0; j <= i; j++) {
                    cout << j + 1 << " ";
                }
                cout << endl;
                break;
            }
        }
    }

    return 0;
}