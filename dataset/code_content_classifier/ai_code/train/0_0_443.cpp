#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> fav_teams(k);
    for(int i = 0; i < k; i++) {
        cin >> fav_teams[i];
    }

    int result = 0;

    // Check if all favorite teams are in the upper bracket
    bool all_upper = true;
    for(int team : fav_teams) {
        if(team > (1 << (n-1))) {
            all_upper = false;
            break;
        }
    }

    if(all_upper) {
        result = (n-1) * 2;
    } else {
        result = (n-1) + 2 + (n-1) * 2;
    }

    cout << result << endl;

    return 0;
}