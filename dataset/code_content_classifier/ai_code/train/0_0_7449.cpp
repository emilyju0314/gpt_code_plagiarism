#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

int main() {
    int q;
    cin >> q;

    deque<int> shelf;
    unordered_map<int, deque<int>::iterator> pos;

    for (int i = 0; i < q; i++) {
        char type;
        int id;
        cin >> type >> id;

        if (type == 'L') {
            shelf.push_front(id);
            pos[id] = shelf.begin();
        } else if (type == 'R') {
            shelf.push_back(id);
            pos[id] = prev(shelf.end());
        } else {
            int left_moves = distance(shelf.begin(), pos[id]);
            int right_moves = distance(pos[id], shelf.end()) - 1;
            cout << min(left_moves, right_moves) << endl;
        }
    }

    return 0;
}