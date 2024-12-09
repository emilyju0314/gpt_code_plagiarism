#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n;
vector<int> cityImportance;
vector<vector<int>> adjList;
vector<long long> subtreeSum;
vector<long long> waysLevel1, waysLevel2;

void dfs(int node, int parent) {
    subtreeSum[node] = cityImportance[node - 1];
    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtreeSum[node] += subtreeSum[neighbor];
        }
    }
}

void countWays(int node, int parent) {
    waysLevel1[node] = 1;
    waysLevel2[node] = 1;
    long long totalWays = 1;
    
    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            countWays(neighbor, node);
            waysLevel1[node] = (waysLevel1[node] * (waysLevel1[neighbor] + waysLevel2[neighbor])) % MOD;
            totalWays = (totalWays * waysLevel1[neighbor]) % MOD;
        }
    }

    for (int neighbor : adjList[node]) {
        if (neighbor != parent) {
            long long temp1 = totalWays / waysLevel1[neighbor];
            long long temp2 = waysLevel1[neighbor] * (waysLevel2[neighbor] + temp1) % MOD;
            waysLevel2[node] = (waysLevel2[node] * temp2) % MOD;
        }
    }
}

int main() {
    int n;
    cin >> n;

    cityImportance.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> cityImportance[i];
    }

    adjList.resize(n + 1);
    subtreeSum.resize(n + 1);
    waysLevel1.resize(n + 1);
    waysLevel2.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adjList[p].push_back(i);
        adjList[i].push_back(p);
    }

    dfs(1, -1);
    if (subtreeSum[1] % n != 0) {
        cout << "0" << endl;
        return 0;
    }

    int target = subtreeSum[1] / n;

    countWays(1, -1);

    long long answer = (waysLevel1[1] + waysLevel2[1]) % MOD;
    cout << answer << endl;

    return 0;
}