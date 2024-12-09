#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ranges;
        vector<int> numbers(n+1);

        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            ranges.push_back({l, r});
        }

        for(auto range : ranges) {
            int l = range.first;
            int r = range.second;
            for(int i = l; i <= r; i++) {
                if(numbers[i] == 0) {
                    numbers[i] = r;
                    break;
                }
            }
        }

        for(auto range : ranges) {
            int l = range.first;
            int r = range.second;
            for(int i = l; i <= r; i++) {
                cout << l << " " << r << " " << numbers[i] << endl;
            }
        }
    }

    return 0;
}