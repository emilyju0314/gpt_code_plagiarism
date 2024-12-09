#include <iostream>
#include <vector>

bool canEscape(std::vector<std::string>& maze, int n, int m) {
    // Check if all good people have a path to cell (n, m)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'G') {
                if((i - 1 >= 0 && maze[i-1][j] == '#') ||
                   (i + 1 < n && maze[i+1][j] == '#') ||
                   (j - 1 >= 0 && maze[i][j-1] == '#') ||
                   (j + 1 < m && maze[i][j+1] == '#')) {
                    return false;
                }
            }
        }
    }
    
    // Check if any bad person has a path to cell (n, m)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'B') {
                if((i - 1 >= 0 && maze[i-1][j] != '#') ||
                   (i + 1 < n && maze[i+1][j] != '#') ||
                   (j - 1 >= 0 && maze[i][j-1] != '#') ||
                   (j + 1 < m && maze[i][j+1] != '#')) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        
        std::vector<std::string> maze(n);
        
        for(int i = 0; i < n; i++) {
            std::cin >> maze[i];
        }
        
        if(canEscape(maze, n, m)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}