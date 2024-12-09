#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countMagicNumbers(int base, long long l, long long r) {
    vector<int> count(11, 0);
    long long curr = l;
    while (curr > 0) {
        int digit = curr % base;
        count[digit]++;
        curr /= base;
    }

    int evenCount = 0;
    for (int i = 0; i < base; i++) {
        if (count[i] % 2 == 0) {
            evenCount++;
        }
    }

    int magicNumbers = 0;
    if (evenCount == base) {
        magicNumbers++;
    }

    for (long long i = l + 1; i <= r; i++) {
        curr = i;
        fill(count.begin(), count.end(), 0);
        while (curr > 0) {
            int digit = curr % base;
            count[digit]++;
            curr /= base;
        }

        evenCount = 0;
        for (int j = 0; j < base; j++) {
            if (count[j] % 2 == 0) {
                evenCount++;
            }
        }

        if (evenCount == base) {
            magicNumbers++;
        }
    }

    return magicNumbers;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int base;
        long long l, r;
        cin >> base >> l >> r;

        int result = countMagicNumbers(base, l, r);
        cout << result << endl;
    }

    return 0;
}