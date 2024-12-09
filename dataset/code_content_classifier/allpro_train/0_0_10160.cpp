#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> skills(4);
        for (int i = 0; i < 4; i++) {
            cin >> skills[i];
        }

        sort(skills.begin(), skills.end(), greater<int>());

        if ((skills[0] > skills[1] && skills[2] > skills[3]) || (skills[0] == skills[1] && skills[2] == skills[3])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}