#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

        int coins = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if(sum < 0) {
                coins += abs(sum);
                sum = 0;
            }
        }

        cout << coins << endl;
    }

    return 0;
}