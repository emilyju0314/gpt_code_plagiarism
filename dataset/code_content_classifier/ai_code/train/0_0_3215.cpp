#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        vector<pair<int, int>> swaps;
        bool possible = true;

        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                bool found = false;
                for(int j = i + 1; j < n; j++) {
                    if(s[j] == s[i]) {
                        swaps.push_back({j+1, i+1});
                        swap(s[j], t[i]);
                        found = true;
                        break;
                    } else if(t[j] == s[i]) {
                        swaps.push_back({i+1, j+1});
                        swap(s[i], t[j]);
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    possible = false;
                    cout << "No" << endl;
                    break;
                }
            }
        }

        if(possible) {
            cout << "Yes" << endl;
            cout << swaps.size() << endl;
            for(auto& swap : swaps) {
                cout << swap.first << " " << swap.second << endl;
            }
        }
    }

    return 0;
}