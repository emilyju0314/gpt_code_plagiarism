#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    long long sum = 0, k = 1;
    while (true) {
        sum += k;
        if (sum % N == 0) {
            cout << k << endl;
            break;
        }
        k++;
    }

    return 0;
}