#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long min_blocks = (8 + n - 1) * 2 + (8 + n - 1) * 2 + 9;
    long long max_blocks = 3 * 2 * n + 1 + 4 * 2 * n + 1;

    cout << min_blocks << " " << max_blocks << endl;

    return 0;
}