#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int num_swaps = 0;

    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    for (int i = 0; i < n; ++i) {
        if (A[i] != sorted_A[i]) {
            num_swaps++;
        }
    }

    cout << num_swaps << endl;

    return 0;
}