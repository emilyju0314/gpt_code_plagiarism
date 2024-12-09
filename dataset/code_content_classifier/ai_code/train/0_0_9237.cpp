#include <iostream>
#include <vector>

using namespace std;

int sum_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        long long l, r;
        int k;
        cin >> l >> r >> k;

        for (int num = l; num <= min(r, 100LL); num++) {
            if (sum_digits(num) <= k) {
                count[k]++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << count[i] << endl;
    }

    return 0;
}