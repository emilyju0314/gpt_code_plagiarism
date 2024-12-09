#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adjList(n + 1);
        vector<int> catOwner(n + 1);

        for (int i = 0; i < m; i++) {
            int resident, cat;
            cin >> resident >> cat;
            adjList[resident].push_back(cat);
            catOwner[cat] = resident;
        }

        vector<int> juryMembers;
        unordered_set<int> contestants;

        for (int i = 1; i <= n; i++) {
            bool isJuryMember = true;
            for (int cat : adjList[i]) {
                if (catOwner[cat] == i) {
                    isJuryMember = false;
                    contestants.insert(cat);
                } else {
                    juryMembers.push_back(i);
                }
            }
            if (isJuryMember) {
                juryMembers.push_back(i);
            }
        }

        if (juryMembers.empty() || contestants.empty()) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << juryMembers.size() << " " << contestants.size() << "\n";

            for (int jury : juryMembers) {
                cout << jury << " ";
            }
            cout << "\n";

            for (int contestant : contestants) {
                cout << contestant << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}