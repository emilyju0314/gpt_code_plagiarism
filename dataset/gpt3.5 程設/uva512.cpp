#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform the operation "m i j"
void operate_mij(vector<int>& permutation, int i, int j) {
    swap(permutation[i], permutation[j]);
}

// Function to perform the operation "r a"
void operate_ra(vector<int>& permutation, int a) {
    reverse(permutation.begin(), permutation.begin() + a);
}

int main() {
    int n, m, caseNum = 0;

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        // Initialize permutation
        vector<int> permutation(n);
        for (int i = 0; i < n; ++i)
            permutation[i] = i + 1;

        // Read operations
        for (int i = 0; i < m; ++i) {
            char op;
            cin >> op;
            if (op == 'M') {
                int a, b;
                cin >> a >> b;
                operate_mij(permutation, a - 1, b - 1);
            }
            else if (op == 'R') {
                int a;
                cin >> a;
                operate_ra(permutation, a);
            }
        }

        // Output
        cout << "Genome " << ++caseNum << endl;
        for (int num : permutation)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
