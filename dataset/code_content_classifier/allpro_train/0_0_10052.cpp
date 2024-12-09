#include <iostream>
#include <vector>
#include <string>

int LCP(const std::string& s, int x, int y) {
    int len = 0;
    while (x < s.size() && y < s.size() && s[x] == s[y]) {
        len++;
        x++;
        y++;
    }
    return len;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    std::vector<std::vector<int>> queries;
    for (int i = 0; i < q; i++) {
        int k, l;
        std::cin >> k >> l;
        
        std::vector<int> a(k), b(l);
        
        for (int j = 0; j < k; j++) {
            std::cin >> a[j];
        }
        
        for (int j = 0; j < l; j++) {
            std::cin >> b[j];
        }
        
        queries.push_back(a);
        queries.push_back(b);
    }
    
    for (int i = 0; i < q*2; i+=2) {
        int sum = 0;
        for (int j = 0; j < queries[i].size(); j++) {
            for (int k = 0; k < queries[i+1].size(); k++) {
                sum += LCP(s, queries[i][j]-1, queries[i+1][k]-1);
            }
        }
        std::cout << sum << std::endl;
    }
    
    return 0;
}