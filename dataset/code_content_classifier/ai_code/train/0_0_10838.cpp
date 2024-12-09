#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        long long sum = 0, xor_val = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            xor_val ^= arr[i];
        }

        if(sum == 2 * xor_val) {
            cout << "0\n";
        } else {
            cout << "2\n";
            cout << xor_val << " " << xor_val << endl;
        }
    }

    return 0;
}