#include <iostream>
#include <vector>
#include <unordered_set>

bool canPlaySong(int n, int m, std::vector<std::string>& stairs, std::vector<std::string>& song) {
    std::unordered_set<std::string> visited;
    int stage = 0;
    
    for(int i = 0; i < m; i++) {
        std::string current_sound = song[i];
        if (visited.count(current_sound)) {
            return false;
        }
        visited.insert(current_sound);
        
        if (stairs[stage] == current_sound) { // same sound, no movement
            continue;
        } else if (stage + 1 <= n && stairs[stage+1] == current_sound) { // go to k+1
            stage++;
        } else if (stage + 2 <= n && stairs[stage+2] == current_sound) { // go to k+2
            stage += 2;
        } else { // k-1
            if (stage <= 0) {
                return false; // cannot go below 0th stage
            }
            stage--;
        }
    }
    
    return true;
}

int main() {
    int datasets;
    std::cin >> datasets;
    
    for (int i = 0; i < datasets; i++) {
        int n, m;
        std::cin >> n >> m;
        
        std::vector<std::string> stairs(n+2);
        for (int j = 1; j <= n; j++) {
            std::cin >> stairs[j];
        }
        
        std::vector<std::string> song(m);
        for (int j = 0; j < m; j++) {
            std::cin >> song[j];
        }
        
        if (canPlaySong(n, m, stairs, song)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}