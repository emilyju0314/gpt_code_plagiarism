#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_set<int> unionSet;

    for (int i = 0; i < n; i++) {
        unordered_set<int> currentSet;
        currentSet.insert(1);
        
        vector<int> toAdd = {1};
        while (!toAdd.empty()) {
            int c = toAdd.back();
            toAdd.pop_back();

            for (int j = 0; j < m; j++) {
                int newElement = (c * a[i] * b[j]) % p;

                if (!currentSet.count(newElement)) {
                    currentSet.insert(newElement);
                    toAdd.push_back(newElement);
                }
            }
        }

        unionSet.insert(currentSet.begin(), currentSet.end());
    }

    cout << unionSet.size() << endl;

    return 0;
}