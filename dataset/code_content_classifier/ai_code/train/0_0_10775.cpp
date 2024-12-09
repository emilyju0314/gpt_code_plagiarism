#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k < n / 2) {
        cout << -1 << endl;
    } else {
        vector<int> sequence;
        int remaining_points = k - (n / 2);
        
        // Generating the first half of the sequence
        for (int i = 1; i <= n / 2; i++) {
            sequence.push_back(i * 2);
        }
        
        // Adding remaining points to the second half of the sequence
        for (int i = 0; i < remaining_points; i++) {
            sequence.push_back(1);
        }
        
        // Output the final sequence
        for (int i = 0; i < n; i++) {
            cout << sequence[i] << " ";
        }
        cout << endl;
    }

    return 0;
}