#include <iostream>
#include <vector>

int main() {
    int M, N, K;
    std::cin >> M >> N >> K;
    
    std::vector<std::vector<char>> terrain(M, std::vector<char>(N));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> terrain[i][j];
        }
    }
    
    for(int i = 0; i < K; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        
        int jungle_count = 0, sea_count = 0, ice_count = 0;
        
        for(int row = a-1; row < c; row++) {
            for(int col = b-1; col < d; col++) {
                if(terrain[row][col] == 'J') {
                    jungle_count++;
                }
                else if(terrain[row][col] == 'O') {
                    sea_count++;
                }
                else if(terrain[row][col] == 'I') {
                    ice_count++;
                }
            }
        }
        
        std::cout << jungle_count << " " << sea_count << " " << ice_count << std::endl;
    }
    
    return 0;
}