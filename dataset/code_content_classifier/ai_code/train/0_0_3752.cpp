#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> first_permutation(n);
    vector<int> second_permutation(n);
    unordered_map<int, int> index_map;

    for(int i = 0; i < n; i++) {
        cin >> first_permutation[i];
        index_map[first_permutation[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> second_permutation[i];
    }

    int max_moves = 0;
    int current_max_index = -1;

    for(int i = 0; i < n; i++) {
        int required_moves = index_map[second_permutation[i]] - i;
        if(required_moves < 0) {
            required_moves += n;
        }

        max_moves = max(max_moves, required_moves);

        current_max_index = max(current_max_index, index_map[second_permutation[i]]);
    }

    int moves = max_moves + current_max_index;

    cout << moves << endl;

    return 0;
}