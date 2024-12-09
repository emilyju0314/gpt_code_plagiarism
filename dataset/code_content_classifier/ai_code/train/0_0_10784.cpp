#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByRange(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> males;
    vector<pair<int, int>> females;

    for (int i = 0; i < n; i++) {
        char gender;
        int a, b;
        
        cin >> gender >> a >> b;

        if (gender == 'M') {
            males.push_back({a, b});
        } else {
            females.push_back({a, b});
        }
    }

    sort(males.begin(), males.end(), sortByRange);
    sort(females.begin(), females.end(), sortByRange);

    int maxFriends = 0;

    for (int i = 0; i < males.size(); i++) {
        for (int j = 0; j < females.size(); j++) {
            if (females[j].second >= males[i].first && females[j].first <= males[i].second) {
                maxFriends += 2;
                females.erase(females.begin() + j);
                break;
            }
        }
    }

    cout << maxFriends << endl;

    return 0;
}