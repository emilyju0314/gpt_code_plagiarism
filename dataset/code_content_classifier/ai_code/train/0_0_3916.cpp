#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> skills(n);
        for (int i = 0; i < n; i++) {
            cin >> skills[i];
        }

        sort(skills.begin(), skills.end(), greater<int>());
        
        int teams = 0;
        int min_skill = skills[0];
        for (int i = 0; i < n; i++) {
            if (skills[i] * (i+1) >= x) {
                teams++;
            } else {
                break;
            }
        }

        cout << teams << endl;
    }

    return 0;
}