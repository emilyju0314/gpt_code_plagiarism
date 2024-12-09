#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    // Calculate the manhattan distance between the two chips
    int dist = abs(x1 - x2) + abs(y1 - y2);

    // If the distance is even, the first player wins
    if (dist % 2 == 0) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}