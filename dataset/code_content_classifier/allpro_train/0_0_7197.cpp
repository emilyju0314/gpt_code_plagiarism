#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    // Calculate the minimal sum
    long long min_sum = 0;
    for(int i = 0; i < l-1; i++) {
        min_sum += pow(2, i);
    }
    min_sum += (n - l + 1);

    // Calculate the maximal sum
    long long max_sum = 0;
    for(int i = 0; i < r-1; i++) {
        max_sum += pow(2, i);
    }
    max_sum += (pow(2, r-1) - 1) * (n - r + 1);

    cout << min_sum << " " << max_sum;

    return 0;
}