#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    map<pair<int, int>, bool> obstacles;
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        obstacles[{X, Y}] = true;
    }

    int actions = 0;
    pair<int, int> curr = {1, 1}; // starting position
    pair<int, int> next = {1, 2}; // next cell to move to

    while(next.first >= 1 && next.first <= H && next.second >= 1 && next.second <= W
          && !obstacles.count(next)) {
        curr = next;
        actions++;
        next = actions % 2 == 0 ? make_pair(curr.first, curr.second + 1) : make_pair(curr.first + 1, curr.second);
    }

    cout << actions << endl;

    return 0;
}