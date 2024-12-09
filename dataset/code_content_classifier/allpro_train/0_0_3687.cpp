#include <iostream>
#include <string>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        cout << i << endl;
        cout.flush();

        string response;
        cin >> response;

        if (response == "yes") {
            if (!is_prime(i)) {
                cout << "composite" << endl;
            } else {
                cout << "prime" << endl;
            }
            cout.flush();
            return 0;
        }
    }

    return 0;
}