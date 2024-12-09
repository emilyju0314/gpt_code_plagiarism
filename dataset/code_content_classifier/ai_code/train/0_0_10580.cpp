#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> categories(n);
        unordered_map<int, int> categoryCount;

        int maxCount = 0;

        for(int i = 0; i < n; i++) {
            cin >> categories[i];
            categoryCount[categories[i]]++;
            maxCount = max(maxCount, categoryCount[categories[i]]);
        }

        int distinctCategories = categoryCount.size();

        if(maxCount > (n + 1) / 2) {
            cout << (n + 1) / 2 << endl;
        } else {
            cout << (n + 2 * distinctCategories - 1) / (2 * distinctCategories) << endl;
        }
    }

    return 0;
}