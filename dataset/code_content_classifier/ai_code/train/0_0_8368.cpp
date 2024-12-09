#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i+1;
    }

    int inversions = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        if (permutation[l-1] > permutation[r-1]) inversions--;
        if (permutation[r-1] > permutation[l-1]) inversions++;

        // Swap elements
        int temp = permutation[l-1];
        permutation[l-1] = permutation[r-1];
        permutation[r-1] = temp;

        cout << inversions << endl;
    }

    return 0;
}