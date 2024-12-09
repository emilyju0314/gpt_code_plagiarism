#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if(a == 0 && b == 0) {
            if(n == 2) {
                cout << "1 2" << endl;
            } else {
                cout << "-1" << endl;
            }
        } else if(a + b > n - 1 || a > n - 1 || b > n - 1 || a == 0 || b == 0) {
            cout << "-1" << endl;
        } else {
            vector<int> permutation(n);
            for(int i = 1; i <= a + 1; i++) {
                permutation[i * 2 - 1] = i;
            }

            int start = 1;
            for(int i = 1; i <= a; i++) {
                for(int j = 0; j < b; j++) {
                    permutation[start + j] = i + a + j + 1;
                }
                start += b;
            }

            for(int i = 1; i <= n; i++) {
                if(permutation[i - 1] == 0) {
                    permutation[i - 1] = a + b + i;
                }
            }

            for(int i = 0; i < n; i++) {
                cout << permutation[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}