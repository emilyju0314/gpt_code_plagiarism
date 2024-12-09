#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<int> horizontal_cuts, vertical_cuts;
    horizontal_cuts.push_back(0);
    horizontal_cuts.push_back(h);
    vertical_cuts.push_back(0);
    vertical_cuts.push_back(w);

    char cut_type;
    int cut_dist;
    for(int i = 0; i < n; i++) {
        cin >> cut_type >> cut_dist;
        if(cut_type == 'H') {
            horizontal_cuts.push_back(cut_dist);
        } else {
            vertical_cuts.push_back(cut_dist);
        }
    }

    sort(horizontal_cuts.begin(), horizontal_cuts.end());
    sort(vertical_cuts.begin(), vertical_cuts.end());

    int max_horizontal_fragment = 0, max_vertical_fragment = 0;
    for(int i = 1; i < horizontal_cuts.size(); i++) {
        max_horizontal_fragment = max(max_horizontal_fragment, horizontal_cuts[i] - horizontal_cuts[i-1]);
    }
    for(int i = 1; i < vertical_cuts.size(); i++) {
        max_vertical_fragment = max(max_vertical_fragment, vertical_cuts[i] - vertical_cuts[i-1]);
    }

    long long area = (long long)max_horizontal_fragment * max_vertical_fragment;
    cout << area << endl;

    for(int i = n-1; i > 0; i--) {
        if(cut_type == 'H') {
            max_horizontal_fragment = max(max_horizontal_fragment, horizontal_cuts[i] - horizontal_cuts[i-1]);
        } else {
            max_vertical_fragment = max(max_vertical_fragment, vertical_cuts[i] - vertical_cuts[i-1]);
        }

        area = (long long)max_horizontal_fragment * max_vertical_fragment;
        cout << area << endl;
    }

    return 0;
}