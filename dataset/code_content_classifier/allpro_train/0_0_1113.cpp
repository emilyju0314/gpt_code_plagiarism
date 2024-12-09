#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N), b(N);
    int xor_a = 0, xor_b = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        xor_a ^= a[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
        xor_b ^= b[i];
    }

    if (xor_a != xor_b) {
        cout << "-1\n";
    } else {
        int num_operations = 0;
        for (int i = 0; i < N; i++) {
            if ((a[i] ^ xor_a) != b[i]) {
                num_operations++;
            }
        }
        cout << num_operations << "\n";
    }

    return 0;
}