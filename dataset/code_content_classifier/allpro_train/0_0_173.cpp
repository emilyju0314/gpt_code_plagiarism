#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int king_x, king_y;
    cin >> king_x >> king_y;

    vector<pair<int, int>> rooks(666);
    for (int i = 0; i < 666; i++) {
        cin >> rooks[i].first >> rooks[i].second;
    }

    // Choose king's initial move
    int target_x = 999;
    int target_y = 999;

    cout << target_x << " " << target_y << endl;
    cout.flush();

    while (true) {
        int move_type, move_x, move_y;
        cin >> move_type >> move_x >> move_y;

        if (move_type == -1) {
            // King is in check, end the program
            break;
        }

        // Update king's position
        king_x = move_x;
        king_y = move_y;

        // Choose next move for the king
        target_x = (king_x != 1) ? 1 : 999;
        target_y = (king_y != 1) ? 1 : 999;

        cout << target_x << " " << target_y << endl;
        cout.flush();
    }

    return 0;
}