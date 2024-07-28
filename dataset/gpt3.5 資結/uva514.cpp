#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> permutation(n);
        while (cin >> permutation[0] && permutation[0]) {
            for (int i = 1; i < n; i++) {
                cin >> permutation[i];
            }

            stack<int> station;
            int current = 1;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                while (current <= permutation[i]) {
                    station.push(current++);
                }

                if (!station.empty() && station.top() == permutation[i]) {
                    station.pop();
                }
                else {
                    valid = false;
                    break;
                }
            }

            cout << (valid ? "Yes" : "No") << endl;
        }

        cout << endl;
    }

    return 0;
}