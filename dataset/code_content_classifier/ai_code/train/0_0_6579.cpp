#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<int> b(m);
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int andHits = 0;
    int orHits = 0;
    std::vector<int> andResult;
    std::vector<int> orResult;

    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(andResult));
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(orResult));

    andHits = andResult.size();
    orHits = orResult.size();
    
    std::cout << andHits << " " << orHits << std::endl;
    for(int i = 0; i < andResult.size(); i++) {
        std::cout << andResult[i] << std::endl;
    }

    for(int i = 0; i < orResult.size(); i++) {
        std::cout << orResult[i] << std::endl;
    }

    return 0;
}