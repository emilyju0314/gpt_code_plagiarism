#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> operations;

    // Check if all blocks are already of the same color
    if (s.find_first_not_of(s[0]) == string::npos) {
        cout << 0 << "\n";
    } else {
        bool can_convert = false;

        // Try to convert all blocks to black
        for (int i = 1; i < n; i++) {
            if (s[i] == 'W') {
                operations.push_back(i);
                s[i] = 'B';
                s[i-1] = s[i-1] == 'W' ? 'B' : 'W';
            }

            if (s.find_first_not_of('B') == string::npos) {
                can_convert = true;
                break;
            }
        }

        // If conversion to all black blocks is not possible, try to convert to all white blocks
        if (!can_convert) {
            s = s.substr(0, n); // Reset the string to initial state
            operations.clear();

            for (int i = 1; i < n; i++) {
                if (s[i] == 'B') {
                    operations.push_back(i);
                    s[i] = 'W';
                    s[i-1] = s[i-1] == 'W' ? 'B' : 'W';
                }

                if (s.find_first_not_of('W') == string::npos) {
                    can_convert = true;
                    break;
                }
            }
        }

        if (can_convert) {
            cout << operations.size() << "\n";
            for (int i = 0; i < operations.size(); i++) {
                cout << operations[i] << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}