#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> digits(n);
    for(int i=0; i<n; i++) {
        cin >> digits[i];
    }

    sort(digits.rbegin(), digits.rend());

    int sum = 0;
    for(int digit : digits) {
        sum += digit;
    }

    if(digits[n-1] != 0 || sum % 3 != 0) {
        cout << -1 << endl;
    } else {
        for(int digit : digits) {
            cout << digit;
        }
        cout << endl;
    }

    return 0;
}