#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canGeneratePermutation(vector<int>& permutation) {
    int n = permutation.size();
    vector<int> count(n + 1, 0);

    for(int i = 0; i < n; i++) {
        count[permutation[i]]++;
    }

    int maxCount = 0;
    for(int i = 1; i <= n; i++) {
        maxCount = max(maxCount, count[i]);
    }

    int undefinedCount = n - maxCount;

    if(undefinedCount >= maxCount - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> permutation(n);
        for(int i = 0; i < n; i++) {
            cin >> permutation[i];
        }

        if(canGeneratePermutation(permutation)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}