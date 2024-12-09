#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int minStepsToEqual(vector<int>& a) {
    int n = a.size();
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, a[i]);
    }
    int steps = 0;
    for (int i = 0; i < n; i++) {
        steps += a[i] / ans;
    }
    return steps;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << minStepsToEqual(a) << endl;
    }

    return 0;
}