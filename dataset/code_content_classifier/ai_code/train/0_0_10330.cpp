#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> demagnetized;
        
        for (int i = 1; i < n; ++i) {
            cout << "? 1 1" << endl;
            cout << i << endl;
            cout << (i+1) << endl;
            cout.flush();

            int force;
            cin >> force;

            if (abs(force) > 1) {
                demagnetized.push_back(i+1);
            }
        }

        cout << "! " << demagnetized.size() << " ";
        for (int i = 0; i < demagnetized.size(); ++i) {
            cout << demagnetized[i] << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}