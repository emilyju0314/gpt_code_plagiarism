#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> towers(n);
    for(int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    vector<pair<int, pair<int, int>>> operations;

    int instability = INT_MAX;
    int moves = 0;

    for(int i = 0; i < k; i++) {
        int min_tower = min_element(towers.begin(), towers.end()) - towers.begin();
        int max_tower = max_element(towers.begin(), towers.end()) - towers.begin();

        if(towers[max_tower] - towers[min_tower] <= 1) {
            instability = towers[max_tower] - towers[min_tower];
            moves = i;
            break;
        }

        towers[max_tower]--;
        towers[min_tower]++;
        operations.push_back({max_tower+1, min_tower+1});
    }

    cout << instability << " " << moves << endl;

    for(auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}