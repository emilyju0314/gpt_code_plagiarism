#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(k, 1); // Initialize all elements of a to 1
        a[0] = n - (k - 1); // Make the first element such that sum of all elements is n

        cout << a[0] << " ";
        
        // Make the rest of the elements 1
        for (int i = 1; i < k; i++) {
            cout << "1 ";
        }

        cout << "\n";
    }

    return 0;
}