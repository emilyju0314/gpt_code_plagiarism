#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;

        bool possible = false;
        for(int i = 0; i < n-1; i++) {
            if(row1[i] == '1' || row2[i] == '1' || (i+1 < n && row1[i+1] == '1') || (i+1 < n && row2[i+1] == '1')) {
                continue;
            } else {
                possible = true;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}