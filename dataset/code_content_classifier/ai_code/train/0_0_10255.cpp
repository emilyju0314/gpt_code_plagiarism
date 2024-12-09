#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> aesthetic_appeal(n);
    unordered_map<int, vector<int>> indices;

    long long max_esthetic_appeal = 0;
    int to_cut = 0;

    for (int i = 0; i < n; i++) {
        cin >> aesthetic_appeal[i];
        indices[aesthetic_appeal[i]].push_back(i + 1);
        max_esthetic_appeal += aesthetic_appeal[i];
    }

    for (auto &it : indices) {
        if (it.second.size() >= 2) {
            to_cut = n - it.second.size();
            max_esthetic_appeal -= it.first * to_cut;
            cout << max_esthetic_appeal << " " << to_cut << endl;
            for (int i = 0; i < it.second.size(); i++) {
                if (to_cut == 0) break;
                cout << it.second[i] << " ";
                to_cut--;
            }
            break;
        }
    }

    return 0;
}