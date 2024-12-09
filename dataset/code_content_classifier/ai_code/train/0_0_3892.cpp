#include <iostream>
#include <vector>
#include <set>

bool isLoop(std::vector<std::vector<std::pair<int, int>>> &floor, int i, int j, std::set<std::pair<int, int>> &visited, std::set<std::pair<int, int>> &path) {
    if (visited.count({i, j}) > 0) {
        return true;
    }
    
    visited.insert({i, j});
    path.insert({i, j});
    int next_i = floor[i][j].first;
    int next_j = floor[i][j].second;
    
    if (path.count({next_i, next_j}) > 0) {
        return false;
    }
    
    return isLoop(floor, next_i, next_j, visited, path);
}

int countLoops(std::vector<std::vector<std::pair<int, int>>> &floor) {
    int N = floor.size();
    int count = 0;
    std::set<std::pair<int, int>> visited;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::set<std::pair<int, int>> path;
            if (isLoop(floor, i, j, visited, path)) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int N;
    
    while (true) {
        std::cin >> N;
        if (N == 0) {
            break;
        }
        
        std::vector<std::vector<std::pair<int, int>>> floor(N, std::vector<std::pair<int, int>>(N));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int x, y;
                std::cin >> x >> y;
                floor[i][j] = {x, y};
            }
        }

        int num_loops = countLoops(floor);
        std::cout << num_loops << std::endl;
    }

    return 0;
}