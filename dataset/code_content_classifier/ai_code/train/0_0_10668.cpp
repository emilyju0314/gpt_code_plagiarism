#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        int max_grannies = 1;
        int current = 1;

        for(int i=0; i<n; i++) {
            current += min(a[i], current-1);
            max_grannies = max(max_grannies, current);
        }

        cout << max_grannies << endl;
    }

    return 0;
}