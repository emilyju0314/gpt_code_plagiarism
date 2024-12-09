#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

vector<int> eulerTotient(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = phi(arr[i]);
    }
    return result;
}

vector<vector<int>> buildGraph(int n) {
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    return adjList;
}

long long dfs(int u, vector<vector<int>>& adjList, vector<int>& values, vector<int>& phiValues, vector<bool>& visited) {
    visited[u] = true;
    long long result = 0;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            result = (result + phiValues[values[u]] * values[u] * phiValues[values[v]] * values[v] + dfs(v, adjList, values, phiValues, visited)) % MOD;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    vector<int> phiValues = eulerTotient(values);
    vector<vector<int>> adjList = buildGraph(n);

    vector<bool> visited(n, false);
    long long result = dfs(0, adjList, values, phiValues, visited);

    long long denominator = (n * 1LL * (n - 1)) % MOD;
    long long inverseDenominator = 1;
    for (long long i = 1; i <= MOD - 2; i++) {
        inverseDenominator = (inverseDenominator * denominator) % MOD;
    }

    long long finalResult = (result * inverseDenominator) % MOD;
    cout << finalResult << endl;

    return 0;
}