#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> conditions(M, vector<int>(3));
    unordered_set<int> unknown_cards;

    for (int i = 0; i < M; i++) {
        cin >> conditions[i][0] >> conditions[i][1] >> conditions[i][2];
        unknown_cards.insert(conditions[i][0]);
        unknown_cards.insert(conditions[i][1]);
    }
    
    int cost = 0;
    for (auto& condition : conditions) {
        int X = condition[0], Y = condition[1], Z = condition[2];
        if (Z % 2 != 0) {
            if (unknown_cards.count(X)) {
                unknown_cards.erase(X);
                cost++;
            } else if (unknown_cards.count(Y)) {
                unknown_cards.erase(Y);
                cost++;
            }
        }
    }

    cout << cost + unknown_cards.size() << endl;
    
    return 0;
}