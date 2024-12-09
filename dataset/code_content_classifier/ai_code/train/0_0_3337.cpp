#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x, y, n, d;
    cin >> x >> y >> n >> d;

    vector<pair<int, int>> vectors(n);
    for(int i = 0; i < n; i++) {
        cin >> vectors[i].first >> vectors[i].second;
    }

    bool antonWins = true;
    for(int i = 1; i <= d; i++) {
        bool antonCanWin = false;

        for(auto vec : vectors) {
            int newX = x + vec.first * i;
            int newY = y + vec.second * i;

            if(sqrt(pow(newX, 2) + pow(newY, 2)) > d) {
                antonCanWin = true;
                break;
            }
        }

        if(!antonCanWin) {
            antonWins = false;
            break;
        }
    }

    if(antonWins) {
        cout << "Anton" << endl;
    } else {
        cout << "Dasha" << endl;
    }

    return 0;
}