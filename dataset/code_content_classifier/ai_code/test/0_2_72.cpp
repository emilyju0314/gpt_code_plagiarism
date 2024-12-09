#include <iostream>

int query(int x, int y) {
    std::cout << "? " << x << " " << y << std::endl;
    std::cout.flush();
    int dist;
    std::cin >> dist;
    return dist;
}

int main() {
    int minX = 1, minY = 1, maxX = 1000000000, maxY = 1000000000;

    // Use binary search to find the enemy base
    while (maxX - minX > 1 || maxY - minY > 1) {
      
        int midX = (minX + maxX) / 2;
        int midY = (minY + maxY) / 2;
        
        int dist = query(midX, midY);

        if (dist == 0) {
            maxX = midX;
            maxY = midY;
            break;
        } else if (dist == -1) {
            return 0;
        }

        int upDist = query(midX, minY);
        if (upDist < dist) {
            maxX = midX;
        } else {
            minX = midX;
        }

        int downDist = query(midX, maxY);
        if (downDist < dist) {
            minX = midX;
        } else {
            maxX = midX;
        }

        int leftDist = query(minX, midY);
        if (leftDist < dist) {
            maxY = midY;
        } else {
            minY = midY;
        }

        int rightDist = query(maxX, midY);
        if (rightDist < dist) {
            minY = midY;
        } else {
            maxY = midY;
        }
    }

    std::cout << "! " << minX << " " << minY << " " << maxX << " " << maxY << std::endl;
    std::cout.flush();

    return 0;
}