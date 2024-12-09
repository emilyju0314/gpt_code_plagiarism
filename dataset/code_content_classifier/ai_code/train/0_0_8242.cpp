#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);

    // Find the first half of the permutation
    vector<int> firstHalf;
    for (int i = 1; i <= n/2; i++) {
        cout << "? 1 " << i << endl;
        cin >> firstHalf[i-1];
    }

    // Find the second half of the permutation
    vector<int> secondHalf;
    for (int i = n/2 + 1; i <= n; i++) {
        cout << "? 1 " << i << endl;
        cin >> secondHalf[i - n/2 - 1];
    }

    // Reconstruct the permutation
    for (int i = 0; i < n/2; i++) {
        permutation[firstHalf[i] - 1] = i + 1;
        permutation[secondHalf[i] - 1] = i + n/2 + 1;
    }

    // Output the permutation
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << permutation[i];
    }
    cout << endl;

    return 0;
}