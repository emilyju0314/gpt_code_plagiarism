#include <iostream>
#include <vector>

using namespace std;

vector<int> getAlmostSortedPermutation(int n, long long k) {
    vector<int> permutation;
    if (k > n) {
        permutation.push_back(-1);
        return permutation;
    }

    for (int i = 1; i <= n; i++) {
        if (k > 1) {
            permutation.push_back(i + 1);
            permutation.push_back(i);
            k -= 2;
            i++;
        } else {
            permutation.push_back(i);
        }
    }

    return permutation;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> result = getAlmostSortedPermutation(n, k);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}