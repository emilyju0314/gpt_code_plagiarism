#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int W, H, n;
    std::cin >> W >> H >> n;
    
    std::vector<int> cuts;
    cuts.push_back(0);
    cuts.push_back(H);
    cuts.push_back(0);
    cuts.push_back(W);
    
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 == x2) {
            cuts.push_back(y1);
        } else {
            cuts.push_back(x1);
        }
    }
    
    std::sort(cuts.begin(), cuts.end());
    
    for(int i = 0; i < cuts.size(); i++) {
        if(i > 0) {
            std::cout << cuts[i] - cuts[i-1] << " ";
        }
    }
    
    return 0;
}