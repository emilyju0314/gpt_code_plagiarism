#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> result;

    for (int i = n; i >= 1; i--) {
        if (result.empty()) {
            result.push_back(i);
        } else {
            int current_gcd = gcd(result.back(), i);
            result.push_back(current_gcd);
        }
    }

    reverse(result.begin(), result.end());

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}