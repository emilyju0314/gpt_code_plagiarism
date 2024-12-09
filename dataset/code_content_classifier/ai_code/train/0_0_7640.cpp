#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cout << "? 1 " << i+1 << endl;
        cin >> permutation[i];
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
}