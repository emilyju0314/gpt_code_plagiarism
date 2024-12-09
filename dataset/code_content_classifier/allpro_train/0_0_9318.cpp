#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Output the maximum possible minimum mex
    cout << 2 << endl;

    // Output the array a with all elements between 0 and 10^9
    vector<int> a(n, 0);
    a[0] = 1;
    for(int i = 1; i < n; i++) {
        a[i] = (a[i-1] + 1) % 2;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}