#include <iostream>
#include <vector>
#include <unordered_map>
#define mod 998244353
using namespace std;

// Function to calculate the number of divisors of a given number
long long divisors(long long n) {
    long long count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;
}

// Function to calculate the number of shortest paths between two vertices
long long shortestPaths(long long D, long long v, long long u) {
    unordered_map<long long, long long> dist;
    dist[v] = 1;
    vector<long long> divv, divu;
    long long dv = divisors(v), du = divisors(u);
    
    // Get all the divisors of v and u
    for (long long i = 1; i * i <= v; i++) {
        if (v % i == 0) {
            divv.push_back(i);
            if (v / i != i) {
                divv.push_back(v / i);
            }
        }
    }
    
    for (long long i = 1; i * i <= u; i++) {
        if (u % i == 0) {
            divu.push_back(i);
            if (u / i != i) {
                divu.push_back(u / i);
            }
        }
    }
    
    // Calculate the shortest path using dynamic programming
    for (long long i : divu) {
        for (long long j : divv) {
            long long w = divisors(i) - (i % j == 0 && (i / j == 1 || i / j == u) && (v % j == 0 && (v / j == u || v / j == 1)));
            dist[i] = (dist[i] + dist[j] * w) % mod;
        }
    }
    
    return dist[u];
}

int main() {
    long long D;
    cin >> D;
    long long q;
    cin >> q;
    
    for (long long i = 0; i < q; i++) {
        long long v, u;
        cin >> v >> u;
        cout << shortestPaths(D, v, u) << endl;
    }
    
    return 0;
}