#include <iostream>
#include <vector>

using namespace std;

vector<int> factorize(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> factors = factorize(n);

        cout << factors.size() << endl;
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i] << " ";
        }
        cout << endl;
    }

    return 0;
}