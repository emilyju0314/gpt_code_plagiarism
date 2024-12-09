#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;

        long long hours = 0;
        if (k >= n) {
            hours = 1;
        } else {
            long long div = n / k;
            long long rem = n % k;
            hours = div * k + min(rem, k / 2);
            if (rem > k / 2) {
                hours += 1;
            }
        }

        cout << hours << endl;
    }

    return 0;
}