#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<int> horizontal_cuts;
    vector<int> vertical_cuts;
    horizontal_cuts.push_back(0);
    horizontal_cuts.push_back(h);
    vertical_cuts.push_back(0);
    vertical_cuts.push_back(w);

    char direction;
    int location;

    for(int i = 0; i < n; i++) {
        cin >> direction >> location;
        if(direction == 'H') {
            horizontal_cuts.push_back(location);
        } else {
            vertical_cuts.push_back(location);
        }
    }

    sort(horizontal_cuts.begin(), horizontal_cuts.end());
    sort(vertical_cuts.begin(), vertical_cuts.end());

    int max_horizontal = 0, max_vertical = 0;
    for(int i = 1; i < horizontal_cuts.size(); i++) {
        max_horizontal = max(max_horizontal, horizontal_cuts[i] - horizontal_cuts[i-1]);
    }
    for(int i = 1; i < vertical_cuts.size(); i++) {
        max_vertical = max(max_vertical, vertical_cuts[i] - vertical_cuts[i-1]);
    }

    cout << max_horizontal * max_vertical << endl;

    return 0;
}