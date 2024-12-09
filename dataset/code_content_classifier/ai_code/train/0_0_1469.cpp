#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

int main() {
    int N;
    
    while (std::cin >> N && N != 0) {
        std::vector<Point> gems(N);
        for (int i = 0; i < N; i++) {
            std::cin >> gems[i].x >> gems[i].y;
        }
        
        int M;
        std::cin >> M;
        
        Point robot = { 10, 10 };
        bool collectedAll = true;
        
        for (int i = 0; i < M; i++) {
            char dir;
            int dist;
            std::cin >> dir >> dist;
            
            switch (dir) {
                case 'N':
                    robot.y += dist;
                    break;
                case 'E':
                    robot.x += dist;
                    break;
                case 'S':
                    robot.y -= dist;
                    break;
                case 'W':
                    robot.x -= dist;
                    break;
            }
            
            for (int j = 0; j < N; j++) {
                if (robot.x == gems[j].x && robot.y == gems[j].y) {
                    gems[j].x = -1; // mark as collected
                    gems[j].y = -1;
                    break;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (gems[i].x != -1 || gems[i].y != -1) {
                collectedAll = false;
                break;
            }
        }
        
        if (collectedAll) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    
    return 0;
}