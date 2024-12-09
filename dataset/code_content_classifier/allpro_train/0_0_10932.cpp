#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long min_blocks = 8 * n + 1;
    long long max_blocks = (n + 1) * (n + 1) * (n + 1) - n;

    cout << min_blocks << " " << max_blocks;

    return 0;
}