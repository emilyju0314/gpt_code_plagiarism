#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        positions[cards[i] - 1] = i;
    }

    vector<vector<int>> operations;

    for (int i = n - 1; i > 0; i--) {
        if (positions[i] != i) {
            vector<int> operation;
            operation.push_back(n - positions[i]);
            for (int j = 0; j < n; j++) {
                if (positions[j] > positions[i]) {
                    operation.push_back(n - positions[j]);
                }
            }
            operations.push_back(operation);

            reverse(cards.begin(), cards.begin() + positions[i] + 1);
            for (int j = 0; j < n; j++) {
                positions[cards[j] - 1] = j;
            }
        }
    }

    cout << operations.size() << endl;
    for (auto operation : operations) {
        cout << operation.size() << " ";
        for (int i = 0; i < operation.size(); i++) {
            cout << operation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}