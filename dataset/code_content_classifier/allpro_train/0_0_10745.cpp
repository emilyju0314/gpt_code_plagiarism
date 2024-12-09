#include <iostream>

using namespace std;

int countTrailingZeros(int n, int b) {
    int result = 0;
    while (n > 0) {
        n /= b;
        result += n;
    }
    return result;
}

int main() {
    long long n, b;
    cin >> n >> b;

    cout << countTrailingZeros(n, b) << endl;

    return 0;
}