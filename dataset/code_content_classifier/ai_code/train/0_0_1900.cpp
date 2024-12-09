#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<int> tiles(12);

int countArrangements(int r, int c, int mask) {
    if (r == R && c == 0) {
        return 1;
    }

    int curr = r * C + c;
    if (mask & (1 << curr)) {
        return countArrangements(r + (c + 1) / C, (c + 1) % C, mask);
    }

    int total = 0;
    for (int i = 0; i < 12; i++) {
        if (tiles[i] > 0) {
            int newMask = mask;
            tiles[i]--;
            newMask |= (1 << curr);
            total += countArrangements(r + (c + 1) / C, (c + 1) % C, newMask);
            tiles[i]++;
        }
    }

    return total;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < 12; i++) {
        cin >> tiles[i];
    }

    cout << countArrangements(0, 0, 0) << endl;

    return 0;
}