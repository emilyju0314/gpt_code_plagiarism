#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, p;
        std::cin >> n >> p;

        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> edges;
        for(int i = 0; i < n-1; i++) {
            int min_gcd = a[i];
            for(int j = i+1; j < n; j++) {
                min_gcd = std::min(min_gcd, gcd(a[i], a[j]));
                if(min_gcd == 1) {
                    break;
                }
                if(min_gcd == a[i]) {
                    edges.push_back(p);
                } else {
                    edges.push_back(min_gcd);
                }
            }
        }

        long long total_weight = 0;
        for(int edge : edges) {
            total_weight += edge;
        }

        std::cout << total_weight << std::endl;
    }

    return 0;
}