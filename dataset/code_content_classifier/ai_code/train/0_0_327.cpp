#include <iostream>
#include <vector>

bool canCollectAllTreasures(int n, std::vector<std::pair<int, int>>& islands) {
    std::vector<bool> visited(n, false);
    visited[0] = true;
    
    int currIsland = 0;
    int totalTreasures = 0;
    while (true) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && totalTreasures + islands[i].first <= islands[i].second) {
                visited[i] = true;
                totalTreasures += islands[i].first;
                found = true;
                currIsland = i;
                break;
            }
        }

        if (!found) {
            break;
        }
    }

    return totalTreasures == n && visited[0];
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::pair<int, int>> islands(n);
        for (int i = 0; i < n; i++) {
            std::cin >> islands[i].first >> islands[i].second;
        }

        if (canCollectAllTreasures(n, islands)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
} 

// Example input:
// 3
// 2 3
// 3 6
// 1 2
// 3
// 2 3
// 3 5
// 1 2
// 0

// Example output:
// Yes
// No