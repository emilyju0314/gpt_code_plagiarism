#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> boxes(n);
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> boxes[i];
        total += boxes[i];
    }

    vector<pair<int, int>> moves;
    int remaining = total;
    bool valid = false;
    for(int i = 0; i < n; i++) {
        if(remaining - boxes[i] != boxes[i]) {
            moves.push_back({i+1, n});
            remaining -= boxes[i];
            valid = true;
        }
    }

    if(valid) {
        cout << moves.size() << endl;
        for(int i = 0; i < moves.size(); i++) {
            cout << moves[i].first << " " << moves[i].second << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}