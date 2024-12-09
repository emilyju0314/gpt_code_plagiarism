#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    int index = 2;
    // Connect bulbs in pairs according to d values
    for (int i = 0; i < n; i++) {
        cout << "1 " << index << endl;
        cout << "1 " << index + 1 << endl;

        index += d[i] + 1;
    }

    // Connect the remaining bulbs to complete the tree structure
    for (int i = 0; i < n - 1; i++) {
        cout << index << " " << index + 2 << endl;
        index += 2;
    }

    return 0;
}