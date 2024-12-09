#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation;
    permutation.push_back(1);

    for (int i = 2; i <= n; i++) {
        int t, j, k;
        cout << "2 1 " << permutation[0] << " " << i << endl;
        cin >> t;

        if (t == -1) {
            permutation.insert(permutation.begin(), i);
        } else {
            permutation.push_back(i);
        }
    }

    cout << "0 ";
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    cout.flush();

    return 0;
}