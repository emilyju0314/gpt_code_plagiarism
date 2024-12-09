#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> balls(n);
        for (int i = 0; i < n; i++) {
            cin >> balls[i];
        }

        set<int> colors;
        for (int i = 0; i < n; i++) {
            colors.insert(balls[i]);
        }

        cout << colors.size() << endl;
    }

    return 0;
}