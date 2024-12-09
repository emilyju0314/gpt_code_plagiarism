#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isKGood(int num, int k) {
    vector<bool> isPresent(10, false);
    while (num > 0) {
        int digit = num % 10;
        if (digit > k) {
            return false;
        }
        isPresent[digit] = true;
        num /= 10;
    }
    for (int i = 0; i <= k; i++) {
        if (!isPresent[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (isKGood(num, k)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}