#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> piles;

    for (int i = 0; i < n; i++) {
        int first_row, second_row;
        cin >> first_row >> second_row;

        vector<string> representations;
        representations.push_back(to_string(first_row) + to_string(second_row));
        representations.push_back(to_string(second_row) + to_string(first_row));
        representations.push_back(to_string(first_row % 10) + to_string(first_row / 10) + to_string(second_row % 10) + to_string(second_row / 10));
        representations.push_back(to_string(second_row % 10) + to_string(second_row / 10) + to_string(first_row % 10) + to_string(first_row / 10));

        for (string rep : representations) {
            piles[rep]++;
        }

        string line;
        cin >> line; // read the separating line
    }

    int num_piles = 0;
    for (auto it = piles.begin(); it != piles.end(); it++) {
        num_piles += (it->second == 1);
    }

    cout << num_piles << endl;

    return 0;
}