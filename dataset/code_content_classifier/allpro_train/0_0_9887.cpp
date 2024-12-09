#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(curr);
            result.push_back(curr + n);
            curr++;
        }

        for (int i = 0; i < 2 * n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}