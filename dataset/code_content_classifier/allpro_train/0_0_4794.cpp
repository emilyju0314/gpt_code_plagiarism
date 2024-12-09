#include <iostream>
#include <string>
#include <cmath>

int main() {
    int t, sx, sy, ex, ey;
    std::cin >> t >> sx >> sy >> ex >> ey;
    
    std::string wind;
    std::cin >> wind;
    
    int time = 0;
    
    for(int i=0; i<t; i++) {
        if(sx < ex && wind[i] == 'E') {
            sx++;
        } else if(sx > ex && wind[i] == 'W') {
            sx--;
        } else if(sy < ey && wind[i] == 'N') {
            sy++;
        } else if(sy > ey && wind[i] == 'S') {
            sy--;
        }
        
        if(sx == ex && sy == ey) {
            time = i+1;
            break;
        }
    }
    
    if(sx == ex && sy == ey) {
        std::cout << time << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}