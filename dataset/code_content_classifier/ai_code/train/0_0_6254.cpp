#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(k);

        for (int i = 0; i < k; i++) {
            p[i] = k - i;
        }

        int remaining = n - k;
        
        for (int i = 0; i < remaining; i++) {
            p.push_back(i + 1);
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }

        cout << endl;
    }

    return 0;
}