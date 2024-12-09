#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> friends;
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        friends.insert({U, V});
        friends.insert({V, U});
    }

    // Loop through all possible combinations of 5 people
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                for (int l = k + 1; l <= N; l++) {
                    for (int m = l + 1; m <= N; m++) {
                        vector<int> party = {i, j, k, l, m};
                        bool success = true;

                        // Check if all people in the party are friends or not friends
                        for (int p = 0; p < 5; p++) {
                            for (int q = p + 1; q < 5; q++) {
                                if (friends.count({party[p], party[q]}) || party[p] == party[q]) {
                                    success = false;
                                    break;
                                }
                            }
                        }

                        if (success) {
                            for (int p = 0; p < 5; p++) {
                                cout << party[p] << " ";
                            }
                            cout << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}