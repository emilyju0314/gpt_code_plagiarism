#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string a, b;

    cin >> n >> a >> b;

    long long ones_a = 0, not_ones_a = 0, ones_b = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            ones_a++;
        } else {
            not_ones_a++;
        }
        if (b[i] == '1') {
            ones_b++;
        }
    }

    long long total_swaps = ones_a * not_ones_a;

    if (ones_b == 0) {
        cout << total_swaps << endl;
    } else {
        long long answer = total_swaps - ones_a * ones_b;
        cout << answer << endl;
    }

    return 0;
}