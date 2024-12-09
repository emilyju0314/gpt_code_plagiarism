#include <iostream>
#include <cmath>

struct WarningLine {
    int x1, y1, x2, y2, thickness;
};

bool isSafeArea(int W, int H, int N, int R, WarningLine* warningLines) {
    for (int i = 0; i < N; i++) {
        WarningLine line = warningLines[i];
        
        // Calculate the distance between the center of the machine and the warning line
        double distance = abs((line.x2 - line.x1) * (line.y1 - R) - (line.x1 - R) * (line.y2 - line.y1)) / sqrt(pow(line.x2 - line.x1, 2) + pow(line.y2 - line.y1, 2));
        
        // Check if there is a safe area
        if (distance <= R + line.thickness)
            return false;
    }
    
    return true;
}

int main() {
    int W, H, N, R;
    
    while (true) {
        std::cin >> W >> H >> N >> R;
        
        if (W == 0 && H == 0 && N == 0 && R == 0)
            break;
        
        WarningLine warningLines[N];
        
        for (int i = 0; i < N; i++) {
            std::cin >> warningLines[i].x1 >> warningLines[i].y1 >> warningLines[i].x2 >> warningLines[i].y2 >> warningLines[i].thickness;
        }
        
        if (isSafeArea(W, H, N, R, warningLines))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    
    return 0;
}