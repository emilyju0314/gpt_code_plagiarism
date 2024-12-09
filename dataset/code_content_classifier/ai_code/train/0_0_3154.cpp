#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int m = 1 + k;

    cout << m << endl;

    for (int i = 0; i < n; i++) {
        vector<int> set;
        int start = 1 + i * k;
        for (int j = 0; j < 4; j++) {
            set.push_back(start + j);
        }

        for (int num : set) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}