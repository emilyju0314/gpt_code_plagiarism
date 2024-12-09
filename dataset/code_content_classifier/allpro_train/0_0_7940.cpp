#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    unordered_map<string, int> wordCosts;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        wordCosts[word] = i;
    }

    vector<int> costs(n);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<vector<int>> groups(k);
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < x; j++) {
            int index;
            cin >> index;
            groups[i].push_back(index - 1);
        }
    }

    long long totalCost = 0;
    for(int i = 0; i < m; i++) {
        string word;
        cin >> word;
        int index = wordCosts[word];

        int minCost = costs[index];
        for(int j = 0; j < k; j++) {
            bool found = false;
            for(int idx : groups[j]) {
                if(idx == index) {
                    found = true;
                    break;
                }
            }
            if(found) {
                for(int idx : groups[j]) {
                    minCost = min(minCost, costs[idx]);
                }
            }
        }
        totalCost += minCost;
    }

    cout << totalCost << endl;

    return 0;
}