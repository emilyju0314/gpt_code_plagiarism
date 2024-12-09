#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> adj;
vector<int> fib;

void calculateFibonacci(int n) {
    fib.push_back(1);
    fib.push_back(1);

    int k = 2;
    while (fib.back() <= n) {
        fib.push_back(fib[k - 1] + fib[k - 2]);
        k++;
    }
}

bool isFibTree(int u, int parent) {
    int sum = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            sum += isFibTree(v, u);
        }
    }

    return binary_search(fib.begin(), fib.end(), sum);
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calculateFibonacci(n);

    bool fibTree = isFibTree(1, -1);

    cout << (fibTree ? "YES" : "NO") << endl;

    return 0;
}