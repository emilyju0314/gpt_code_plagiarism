#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void buildDecomposition(vector<int>& p, vector<vector<int>>& l) {
    l.clear();
    vector<bool> marked(p.size(), false);
    for (int i = 0; i < p.size(); i++) {
        if (!marked[i]) {
            vector<int> curList;
            int j = i;
            do {
                marked[j] = true;
                curList.push_back(p[j]);
                j = p[j] - 1;
            } while (j != i);
            sort(curList.begin(), curList.end(), greater<int>());
            l.push_back(curList);
        }
    }
}

vector<int> getKthGoodPermutation(int n, long long k) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    do {
        vector<vector<int>> decomposition;
        buildDecomposition(p, decomposition);
        if (decomposition.size() == 1 && k == 1) {
            return p;
        }
    } while (next_permutation(p.begin(), p.end()));

    return vector<int>();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> goodPermutation = getKthGoodPermutation(n, k);
        
        if (goodPermutation.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << goodPermutation[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}