#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> rounds(n);
    int max_round = 0;
    for (int i = 0; i < n; i++) {
        cin >> rounds[i];
        max_round = max(max_round, abs(rounds[i]));
    }

    int k = 0;
    vector<int> deck;
    for (int i = 0; i < n; i++) {
        int ai = rounds[i];
        if (ai < 0) {
            deck.push_back(-1);
            deck.push_back(-ai-1);
            k = max(k, -ai);
        } else {
            deck.push_back(ai);
            k = max(k, ai);
        }
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << deck[i] << " ";
    }
    cout << endl;

    return 0;
}