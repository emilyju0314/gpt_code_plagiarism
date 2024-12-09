#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> minLexicographicalPermutation(vector<int>& permutation) {
    int n = permutation.size();
    vector<int> result = permutation;

    for (int i = 0; i < n - 1; i++) {
        if (permutation[i] > permutation[i+1]) {
            int j = i + 1;
            while (j < n - 1 && permutation[j] > permutation[j+1]) {
                j++;
            }
            reverse(permutation.begin() + i, permutation.begin() + j + 1);
            break;
        }
    }

    return result;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> permutation(n);
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
        }

        vector<int> result = minLexicographicalPermutation(permutation);
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}