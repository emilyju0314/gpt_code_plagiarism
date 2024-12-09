#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> daughters(n);
        unordered_set<int> married;
        bool improved = false;
        pair<int, int> answer;

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int g;
                cin >> g;
                daughters[i].push_back(g);
            }
            
            if (!improved) {
                for (int g : daughters[i]) {
                    if (married.find(g) == married.end()) {
                        married.insert(g);
                        improved = true;
                        answer = make_pair(i+1, g);
                        break;
                    }
                }
            }
        }

        if (improved) {
            cout << "IMPROVE" << endl;
            cout << answer.first << " " << answer.second << endl;
        } else {
            cout << "OPTIMAL" << endl;
        }
    }

    return 0;
}