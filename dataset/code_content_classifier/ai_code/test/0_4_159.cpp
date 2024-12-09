#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> subset;

    for (int i = 1; i <= n; i++) {
        if (i % 4 == 1 || i % 4 == 2) {
            subset.push_back(i);
        }
    }

    cout << subset.size() << endl;
    for (int i : subset) {
        cout << i << " ";
    }

    return 0;
}