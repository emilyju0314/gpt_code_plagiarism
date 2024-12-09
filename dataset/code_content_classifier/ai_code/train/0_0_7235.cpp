#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int g;
    cin >> g;

    vector<string> games(g);
    unordered_map<string, int> gameIndex;

    for (int i = 0; i < g; i++) {
        cin >> games[i];
        gameIndex[games[i]] = i + 1; // 1-indexing for easier printing later
    }

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> count;
        for (int j = 0; j < k; j++) {
            string game = s.substr(i * k + j, k);
            count[game]++;
        }

        bool found = false;
        vector<int> result(n);

        for (int j = 0; j < n; j++) {
            string game = s.substr(j * k, k);
            if (count[game] == 1) {
                count[game]--;
                result[0] = gameIndex[game];
                for (int x = 1; x < n; x++) {
                    game = s.substr((j + x) * k, k);
                    count[game]--;
                    result[x] = gameIndex[game];
                }
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
            for (int j = 0; j < n; j++) {
                cout << result[j] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}