#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<string>> cards(n, vector<string>(m));
    vector<vector<char>> rank(n, vector<char>(m));
    vector<vector<char>> suit(n, vector<char>(m));

    // Input cards and separate rank and suit
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cards[i][j];
            rank[i][j] = cards[i][j][0];
            suit[i][j] = cards[i][j][1];
        }
    }

    // Check if the solitaire can be solved

    // Determine the cards that replace the jokers

    // Print the output

    return 0;
}