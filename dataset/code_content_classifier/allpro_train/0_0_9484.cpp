#include <iostream>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    long long result = 1;
    for(int i = 1; i < n; i++) {
        result = (result * k) % m;
    }

    cout << (result * k) % m << endl;

    return 0;
}