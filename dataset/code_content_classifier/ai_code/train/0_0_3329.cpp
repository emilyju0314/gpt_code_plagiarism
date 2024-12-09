#include <iostream>
#include <bitset>

using namespace std;

int num_bits_set(unsigned long long n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        unsigned long long l, r;
        cin >> l >> r;

        unsigned long long x = l;
        for (int j = 63; j >= 0; j--) {
            if ((x | (1ULL << j)) <= r) {
                x |= (1ULL << j);
            }
        }

        cout << x << endl;
    }

    return 0;
}