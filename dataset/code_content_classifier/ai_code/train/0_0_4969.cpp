#include <iostream>
#include <vector>
#include <algorithm>

struct Line {
    int x, y, len;
};

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<Line> north_south(n);
    std::vector<Line> west_east(m);
    
    for(int i = 0; i < n; i++) {
        int x, y, len;
        std::cin >> x >> y >> len;
        north_south[i] = {x, y, len};
    }
    
    for(int i = 0; i < m; i++) {
        int x, y, len;
        std::cin >> x >> y >> len;
        west_east[i] = {x, y, len};
    }
    
    int max_size = 0;
    
    for(auto ns : north_south) {
        for(auto we : west_east) {
            int center_x = ns.x;
            int center_y = we.y;
            
            int min_dist = std::min({
                abs(center_x - ns.x),
                abs(center_x - (ns.x + ns.len)),
                abs(center_y - we.y),
                abs(center_y - (we.y + we.len))
            });
            
            max_size = std::max(max_size, min_dist);
        }
    }
    
    std::cout << max_size << std::endl;
    
    return 0;
}