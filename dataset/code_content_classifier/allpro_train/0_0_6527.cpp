#include <iostream>
#include <vector>
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
    int k;
    cin >> k;

    vector<int> beautiful_set;

    for (int i = 1; beautiful_set.size() < k; i++) {
        if (is_prime(i)) {
            beautiful_set.push_back(i);
            for (int j = 2 * i; j <= 2*k*k; j *= 2) {
                beautiful_set.push_back(j);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << beautiful_set[i] << " ";
    }

    return 0;
}