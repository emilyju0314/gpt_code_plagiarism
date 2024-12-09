#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        vector<int> dishes(n);
        for(int i = 0; i < n; i++) {
            cin >> dishes[i];
        }

        sort(dishes.begin(), dishes.end());

        int min_unpleasant = 0;
        for(int i = 0; i < n; i++) {
            min_unpleasant = max(min_unpleasant, min(dishes[i], n - i));
        }

        cout << min_unpleasant << endl;
    }

    return 0;
}