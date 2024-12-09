#include <iostream>

int main() {
    int H, W, h, w;
    std::cin >> H >> W >> h >> w;
    
    int total_cells = H * W;
    int painted_cells = h * W + w * (H - h);
    int remaining_cells = total_cells - painted_cells;
    
    std::cout << remaining_cells << std::endl;
    
    return 0;
}