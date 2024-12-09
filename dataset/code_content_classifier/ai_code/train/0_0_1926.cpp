#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> calculateAmazingNumbers(vector<int>& a) {
    int n = a.size();
    vector<int> result(n, -1); // Initialize all elements with -1
    unordered_set<int> uniqueNums; // Store unique numbers in subsegment

    for (int k = 1; k <= n; k++) {
        uniqueNums.clear();
        int minNum = INT_MAX;

        for (int i = 0; i < k; i++) {
            uniqueNums.insert(a[i]);
        }

        for (int i = k; i < n; i++) {
            if (uniqueNums.count(a[i]) == 0) { // Element not found in subsegment
                minNum = -1;
            }
        }

        if (minNum != -1) {
            for (int num : uniqueNums) {
                minNum = min(minNum, num);
            }
        }

        result[k-1] = minNum;
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> result = calculateAmazingNumbers(a);

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }

        cout << endl;
    }

    return 0;
}