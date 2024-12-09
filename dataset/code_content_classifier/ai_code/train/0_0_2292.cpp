#include <iostream>
#include <vector>

using namespace std;

int n;

void printArrangement(vector<vector<int>> piles) {
    cout << piles.size() << endl;
    for (auto pile : piles) {
        for (int i = 0; i < pile.size(); i++) {
            cout << pile[i];
            if (i < pile.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void generateArrangements(vector<vector<int>>& piles, vector<int> toys, int pos) {
    if (pos == n) {
        printArrangement(piles);
        return;
    }

    for (int i = 0; i <= piles.size(); i++) {
        vector<vector<int>> newPiles = piles;
        newPiles.insert(newPiles.begin() + i, vector<int>(1, toys[pos]));
        generateArrangements(newPiles, toys, pos+1);
    }
}

int main() {
    cin >> n;

    vector<vector<int>> initialPile(1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        initialPile[0][i] = i+1;
    }

    vector<int> toys(n);
    for (int i = 0; i < n; i++) {
        toys[i] = i+1;
    }

    generateArrangements(initialPile, toys, 1);

    return 0;
}