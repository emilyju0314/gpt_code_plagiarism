#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

long long power(int x, int y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y = y / 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> special_numbers;
        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < 31; j++) {
                long long special_number = power(n, i) + power(n, j);
                special_numbers.push_back(special_number % mod);
            }
        }

        sort(special_numbers.begin(), special_numbers.end());
        
        cout << special_numbers[k-1] << endl;
    }

    return 0;
}