#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation;
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }

    for (int i = n; i > 0; i--) {
        cout << i << " ";
    }

    return 0;
}