#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> columns(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> columns[i];
            sum += columns[i];
        }

        if(sum % 2 == 1) {
            cout << "NO" << endl;
        } else {
            bool possible = true;
            for(int i = 0; i < n; i++) {
                if(columns[i] % 2 == 1) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}