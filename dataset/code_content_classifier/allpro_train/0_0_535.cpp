#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> chairs;
        for (int i = 1; i <= 4 * n; i++) {
            chairs.push_back(i);
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(chairs[2 * i + 1]);
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}