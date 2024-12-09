#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long sum = 0;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int allowance;
        cin >> allowance;
        
        if (allowance >= m) {
            sum += m;
            prev = m;
        } else {
            sum += prev + 1;
            prev = prev + 1;
        }
    }

    cout << sum << endl;

    return 0;
}