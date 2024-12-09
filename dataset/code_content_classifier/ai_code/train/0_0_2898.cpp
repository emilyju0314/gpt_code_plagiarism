#include <iostream>

using namespace std;

int main() {
    long long k, a, b;
    cin >> k >> a >> b;

    long long count = (b / k) - (a / k);
    if (a % k == 0) {
        count++;
    }

    cout << count << endl;

    return 0;
}