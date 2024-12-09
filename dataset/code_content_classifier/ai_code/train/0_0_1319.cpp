#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (is_prime(s.length())) {
        cout << "YES" << endl;
        cout << s << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}