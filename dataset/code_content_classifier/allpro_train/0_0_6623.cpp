#include <iostream>

using namespace std;

int main() {
    long long A;
    cin >> A;

    long long count = 0;
    for (long long i = 1; i * i <= A; i++) {
        if (A % i == 0) {
            count++;
        }
        if (i * i != A) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}