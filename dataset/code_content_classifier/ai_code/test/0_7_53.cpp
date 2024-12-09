#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        vector<int> operations;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                operations.push_back(i);
            }
        }

        cout << operations.size() << endl;
        for (int i = 0; i < operations.size(); i++) {
            cout << operations[i] << " ";
        }
        cout << endl;
    }

    return 0;
}