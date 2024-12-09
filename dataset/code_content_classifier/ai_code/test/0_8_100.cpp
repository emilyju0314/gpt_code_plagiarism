#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int min_element = INT_MAX;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            min_element = min(min_element, a[i]);
        }

        cout << min_element << endl;
    }

    return 0;
}