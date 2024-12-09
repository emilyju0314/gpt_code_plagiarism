#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    long long largestPower = 0;

    for (int i = 0; i < n-1; i++) {
        largestPower += max(powers[i], powers[i+1]);
    }

    cout << largestPower << endl;

    return 0;
}