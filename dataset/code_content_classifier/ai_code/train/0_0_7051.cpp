#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> permutation(n);

    int oddNum = 1;
    int evenNum = 2;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            permutation[i] = oddNum;
            oddNum += 2;
        } else {
            permutation[i] = evenNum;
            evenNum += 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
}