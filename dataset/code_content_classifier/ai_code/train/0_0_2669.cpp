#include <iostream>
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b >> x;

    long long count = 0;
    for (long long i = a; i <= b; i++) {
        if (i % x == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}