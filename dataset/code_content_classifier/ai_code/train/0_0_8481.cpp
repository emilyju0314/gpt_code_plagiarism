#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int m, n, a, b, c, d;
    cin >> m >> n >> a >> b >> c >> d;

    // Initialize variables and set to keep track of visited squares
    int jumps = 0;
    unordered_set<int> visited;

    int x = 0, y = 0;
    while (true) {
        // Calculate the next position of the rabbit
        int next_x1 = (x + a) % m;
        int next_y1 = (y + b) % n;
        int next_x2 = (x + c) % m;
        int next_y2 = (y + d) % n;

        // Check if the rabbit is stuck in a loop
        int pos1 = next_x1 * n + next_y1;
        int pos2 = next_x2 * n + next_y2;

        if (visited.count(pos1) && visited.count(pos2)) {
            break;
        }

        // Update the position of the rabbit and increment the number of jumps
        visited.insert(pos1);
        visited.insert(pos2);
        x = next_x1;
        y = next_y1;
        jumps++;
    }

    cout << jumps << endl;

    return 0;
}