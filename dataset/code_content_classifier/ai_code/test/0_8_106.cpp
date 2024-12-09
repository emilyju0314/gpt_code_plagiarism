#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n, 1); // Initialize array with 1's

        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] * 2; // Ensure that a_i isn't divisible by a_{i-1}
        }

        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}