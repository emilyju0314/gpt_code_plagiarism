#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> found1(n);
    vector<int> found2(n);
    vector<int> key(n);

    for(int i=0; i<n; i++) {
        cin >> found1[i];
    }

    for(int i=0; i<n; i++) {
        cin >> found2[i];
    }

    for(int i=0; i<n; i++) {
        key[i] = (found1[i] + found2[i]) % m;
    }

    for(int i=n-1; i>=0; i--) {
        cout << key[i] << " ";
    }

    return 0;
}