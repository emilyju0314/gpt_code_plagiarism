#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+2; j < n; j++) {
            int xor_val = a[i] ^ a[j];
            int sum_val = 0;
            for (int k = i+1; k < j; k++) {
                sum_val += a[k];
            }
            if (xor_val == sum_val) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}