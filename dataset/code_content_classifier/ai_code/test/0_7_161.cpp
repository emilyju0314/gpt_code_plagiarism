#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ranges;
        map<pair<int, int>, int> picked_numbers;

        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            ranges.push_back(make_pair(l, r));
        }

        sort(ranges.begin(), ranges.end());

        int current_number = 1;
        for(auto r : ranges) {
            picked_numbers[r] = current_number;
            current_number++;
        }

        for(auto range : ranges) {
            cout << range.first << " " << range.second << " " << picked_numbers[range] << endl;
        }
    }

    return 0;
}