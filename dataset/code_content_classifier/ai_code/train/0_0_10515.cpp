#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x, y, z, p;
    cin >> n >> m >> x >> y >> z >> p;

    vector<pair<int, int>> candies(p);
    for(int i = 0; i < p; i++) {
        cin >> candies[i].first >> candies[i].second;
    }

    for(int i = 0; i < x % 4; i++) {
        for(int j = 0; j < p; j++) {
            int tmp = candies[j].first;
            candies[j].first = candies[j].second;
            candies[j].second = n - tmp + 1;
        }
        swap(n, m);
    }

    for(int i = 0; i < y % 2; i++) {
        for(int j = 0; j < p; j++) {
            candies[j].second = m - candies[j].second + 1;
        }
    }

    for(int i = 0; i < z % 4; i++) {
        for(int j = 0; j < p; j++) {
            int tmp = candies[j].second;
            candies[j].second = candies[j].first;
            candies[j].first = m - tmp + 1;
        }
        swap(n, m);
    }

    for(auto candy : candies) {
        cout << candy.first << " " << candy.second << endl;
    }

    return 0;
}