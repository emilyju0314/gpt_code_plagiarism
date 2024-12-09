#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int xor_sum = 0;
    for (int i = 0; i < 31; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i)) {
                count++;
            }
        }
        xor_sum ^= ((1 << i) % (2 * n)) * count * (n - count);
    }

    cout << xor_sum << endl;

    return 0;
}