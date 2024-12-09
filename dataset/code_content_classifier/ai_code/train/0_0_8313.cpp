#include <iostream>
#include <set>

int main() {
    int H, W, S, T;
    std::cin >> H >> W >> S >> T;

    std::set<std::pair<int, int>> visited;

    visited.insert({S, T});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++) {
        int nx = S + dx[i];
        int ny = T + dy[i];
        if(nx >= 1 && ny >= 1 && nx <= H && ny <= W) {
            visited.insert({nx, ny});
        }
    }
    
    std::cout << (visited.size() == H*W ? "Yes" : "No") << std::endl;

    return 0;
}