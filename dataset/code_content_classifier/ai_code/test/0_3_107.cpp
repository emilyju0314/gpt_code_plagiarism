#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if(a + b > n - 1 || a > n / 2 || b > n / 2) {
            cout << -1 << endl;
        } else {
            vector<int> permutation;

            for(int i = 0; i < a; i++) {
                permutation.push_back(n - a + i * 2);
            }

            int remaining = n - a;
            for(int i = 0; i < b; i++) {
                permutation.insert(permutation.begin() + i * 2 + 1, remaining - b + i * 2);
            }

            for(int num : permutation) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}