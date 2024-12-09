#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count2020 = n % 2021;
        int count2021 = (n - count2020*2020) / 2020;

        if (count2021 >= 0 && count2020 >= 0 && count2020*2020 + count2021*2021 == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}