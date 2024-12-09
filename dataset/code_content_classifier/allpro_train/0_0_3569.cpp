#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > (n-1)/2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<int> children(n+1, 0);

        int imbalanced = 0;
        for (int i = 2; i <= n; i++) {
            if (imbalanced < k) {
                children[i] = 1;
                imbalanced++;
            } else {
                children[i] = i/2;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << children[i] << " ";
        }
        cout << endl;
    }

    return 0;
}