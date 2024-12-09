#include <iostream>
#include <vector>
#include <set>

void query(int x, std::vector<int>& neighbors) {
    std::cout << "? " << x << std::endl;
    std::cout.flush();
    int k;
    std::cin >> k;
    neighbors.resize(k);
    for (int i = 0; i < k; i++) {
        std::cin >> neighbors[i];
    }
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        int h;
        std::cin >> h;
        
        std::vector<int> neighbors;
        query(1, neighbors);
        if (neighbors.size() == 2) {
            std::cout << "! 1" << std::endl;
            std::cout.flush();
            continue;
        }

        int node = neighbors[0];
        std::set<int> visited;
        visited.insert(1);
        visited.insert(node);

        query(node, neighbors);
        while (neighbors.size() != 2) {
            int next_node = neighbors[0];
            visited.insert(next_node);
            query(next_node, neighbors);
            node = next_node;
        }

        for (int j = 2; j <= (1 << (h-1)); j++) {
            if (visited.count(j) == 0) {
                node = j;
                break;
            }
        }

        std::cout << "! " << node << std::endl;
        std::cout.flush();
    }

    return 0;
}