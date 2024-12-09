#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> skills(n);
    for(int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    vector<int> team(n, 0); // 0 represents no team chosen yet

    int pred = -1;
    for(int i = 0; i < n; i++) {
        auto it = max_element(skills.begin() + max(0, i - k), skills.begin() + min(n, i + k + 1));
        int idx = it - skills.begin();
        
        if((*it) > pred) {
            team[idx] = (i % 2 == 0) ? 1 : 2;
            pred = *it;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << team[i];
    }
    cout << endl;

    return 0;
}