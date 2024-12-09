#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<string> panels(4);
    for(int i = 0; i < 4; i++) {
        cin >> panels[i];
    }

    vector<int> count(10, 0);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(panels[i][j] != '.') {
                count[panels[i][j] - '0']++;
            }
        }
    }

    for(int i = 1; i <= 9; i++) {
        if(count[i] > 2*k) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}