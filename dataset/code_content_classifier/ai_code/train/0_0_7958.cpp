#include <iostream>
#include <vector>
#include <algorithm>

struct Triple {
    int x, y, z;
};

bool TripleCompare(const Triple& a, const Triple& b) {
    return a.x < b.x && a.y < b.y && a.z < b.z;
}

int main() {
    int m, n, A, B;
    
    while (true) {
        std::cin >> m >> n >> A >> B;
        
        if (m == 0 && n == 0 && A == 0 && B == 0) {
            break;
        }
        
        std::vector<Triple> triples;
        
        for (int i = 0; i < m; i++) {
            Triple t;
            std::cin >> t.x >> t.y >> t.z;
            triples.push_back(t);
        }
        
        int a = A, b = B, C = ~(1<<31), M = (1<<16)-1;
        
        for (int i = 0; i < n; i++) {
            Triple t;
            a = 36969 * (a & M) + (a >> 16);
            b = 18000 * (b & M) + (b >> 16);
            t.x = (C & ((a << 16) + b)) % 1000000;
            a = 36969 * (a & M) + (a >> 16);
            b = 18000 * (b & M) + (b >> 16);
            t.y = (C & ((a << 16) + b)) % 1000000;
            a = 36969 * (a & M) + (a >> 16);
            b = 18000 * (b & M) + (b >> 16);
            t.z = (C & ((a << 16) + b)) % 1000000;
            triples.push_back(t);
        }
        
        std::sort(triples.begin(), triples.end(), TripleCompare);
        
        std::vector<int> dp(triples.size(), 1);
        int maxLength = 1;
        
        for (int i = 1; i < triples.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (TripleCompare(triples[j], triples[i])) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }
        
        std::cout << maxLength << std::endl;
    }
    
    return 0;
}