#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> edges;
    
    for (int i = 1; i <= n; i++) {
        if (isPrime(i + 1)) {
            edges.push_back({1, i+1});
        } else {
            int primeVertex = 0;
            for (int j = i+1; j <= n; j++) {
                if (isPrime(j + 1)) {
                    primeVertex = j+1;
                    break;
                }
            }
            if (primeVertex == 0) {
                cout << -1 << endl;
                return 0;
            }
            edges.push_back({i, primeVertex});
        }
    }
    
    int m = edges.size();
    cout << m << endl;
    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    return 0;
}