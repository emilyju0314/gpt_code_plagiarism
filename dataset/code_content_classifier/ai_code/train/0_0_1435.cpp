#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = 0, i = 1;
    while (n > sum + i) {
        sum += i;
        i++;
    }

    cout << n - sum << endl;

    return 0;
}