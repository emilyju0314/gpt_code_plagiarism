#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if (n <= 3) {
            cout << -1 << endl;
        } else {
            vector<int> permutation;
            for (int i = n; i >= 1; i -= 4) {
                for (int j = i; j > max(i - 4, 1); --j) {
                    permutation.push_back(j);
                }
            }

            for (int i = 0; i < n; ++i) {
                cout << permutation[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}