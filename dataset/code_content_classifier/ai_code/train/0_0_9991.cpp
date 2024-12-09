// C++ program to find the winner of the game
#include <bits/stdc++.h>
using namespace std;

// Function to find the winner based on the number of cuts
void findWinner(int n, int m, int k, vector<pair<int, int>> vertical, vector<pair<int, int>> horizontal) {
    int xorSum = 0;

    // Calculate the xor of the number of cuts for each row and column
    for (int i = 0; i < vertical.size(); i++) {
        xorSum ^= (vertical[i].second - vertical[i].first - 1);
    }
    for (int i = 0; i < horizontal.size(); i++) {
        xorSum ^= (horizontal[i].second - horizontal[i].first - 1);
    }

    // If xor sum is zero, second player wins
    if (xorSum == 0) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;

        // Find the winning move for the first player
        for (int i = 0; i < vertical.size(); i++) {
            int numBlocks = vertical[i].second - vertical[i].first - 1;
            xorSum ^= numBlocks;
            if ((xorSum ^ numBlocks) <= numBlocks) {
                cout << vertical[i].first << " " << 0 << " " << vertical[i].second << " " << m << endl;
                return;
            }
            xorSum ^= numBlocks;
        }

        for (int i = 0; i < horizontal.size(); i++) {
            int numBlocks = horizontal[i].second - horizontal[i].first - 1;
            xorSum ^= numBlocks;
            if ((xorSum ^ numBlocks) <= numBlocks) {
                cout << 0 << " " << horizontal[i].first << " " << n << " " << horizontal[i].second << endl;
                return;
            }
            xorSum ^= numBlocks;
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Separate vertical and horizontal cuts
    vector<pair<int, int>> vertical, horizontal;
    for (int i = 0; i < k; i++) {
        int xbi, ybi, xei, yei;
        cin >> xbi >> ybi >> xei >> yei;
        if (xbi == xei) {
            vertical.push_back({min(ybi, yei), max(ybi, yei)});
        } else {
            horizontal.push_back({min(xbi, xei), max(xbi, xei)});
        }
    }

    // Find the winner of the game
    findWinner(n, m, k, vertical, horizontal);

    return 0;
}