#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    vector<set<int>> adjList(n+1);
    unordered_map<int, int> recognition;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = make_pair(a, b);
        adjList[a].insert(b);
        adjList[b].insert(a);
        recognition[a]++;
        recognition[b]++;
    }

    int minSumRecognition = -1;

    for (int i = 1; i <= n; i++) {
        for (int j : adjList[i]) {
            for (int k : adjList[j]) {
                if (adjList[i].count(k)) {
                    int sumRecognition = recognition[i] + recognition[j] + recognition[k] - 6;
                    if (minSumRecognition == -1 || sumRecognition < minSumRecognition) {
                        minSumRecognition = sumRecognition;
                    }
                }
            }
        }
    }

    cout << minSumRecognition << endl;

    return 0;
}