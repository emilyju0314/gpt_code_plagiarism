#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> cityMap;
map<int, string> reverseCityMap;
vector<vector<int>> adjList;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << reverseCityMap[node] << endl;
    for (int i = 0; i < adjList[node].size(); i++) {
        int nextNode = adjList[node][i];
        if (!visited[nextNode]) {
            dfs(nextNode);
        }
    }
}

int main() {
    int caseNum = 1;
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        cityMap.clear();
        reverseCityMap.clear();
        adjList.clear();
        visited.clear();

        cityMap[""] = -1;
        adjList.resize(n + 1);
        visited.resize(n + 1, false);

        int index = 1;
        for (int i = 0; i < m; i++) {
            string city1, city2;
            cin >> city1 >> city2;
            if (cityMap.find(city1) == cityMap.end()) {
                cityMap[city1] = index;
                reverseCityMap[index] = city1;
                index++;
            }
            if (cityMap.find(city2) == cityMap.end()) {
                cityMap[city2] = index;
                reverseCityMap[index] = city2;
                index++;
            }

            int u = cityMap[city1];
            int v = cityMap[city2];
            adjList[u].push_back(v);
        }

        if (caseNum > 1) {
            cout << endl;
        }
        cout << "Calling circles for data set " << caseNum << ":" << endl;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        caseNum++;
    }

    return 0;
}
