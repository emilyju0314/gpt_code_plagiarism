#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> angles(N);
    for(int i = 0; i < N; i++) {
        cin >> angles[i];
    }

    vector<pair<int, int>> coords;
    if(N % 2 == 0) {
        cout << -1 << endl;
    } else {
        int x = 0, y = 0;
        coords.push_back({x, y});
        for(int i = 0; i < N; i++) {
            if(i % 4 == 0) {
                x += 1;
            } else if(i % 4 == 1) {
                y += 1;
            } else if(i % 4 == 2) {
                x -= 1;
            } else if(i % 4 == 3) {
                y -= 1;
            }
            coords.push_back({x, y});
        }

        for(int i = 0; i < N; i++) {
            cout << coords[i].first << " " << coords[i].second << endl;
        }
    }

    return 0;
}