#include <iostream>
#include <vector>
#include <algorithm>

void play_game_as_Alice(int n, const std::vector<std::vector<int>>& a) {
    std::cout << "A" << std::endl;
    // Choose the strategy for Alice to be "decreasing"
    std::cout << "D 1" << std::endl;
    std::cout.flush();

    int current_node = 1;
    // Keep track of visited nodes
    std::vector<bool> visited(n*2 + 1, false);
    visited[current_node] = true;

    while (true) {
        int next_node;
        std::cin >> next_node;

        if (next_node == -1) {
            // Judge has no legal moves left, Alice wins
            break;
        } else if (!visited[next_node]) {
            current_node = next_node;
            visited[current_node] = true;

            // Find the edge weight for the current edge
            int edge_weight = a[current_node - 1][current_node - n - 1];

            std::vector<int> possible_next_nodes;
            for (int i = 1; i <= n; ++i) {
                if (!visited[i] && a[current_node - 1][i - 1] > edge_weight) {
                    possible_next_nodes.push_back(i);
                }
            }

            std::cout << possible_next_nodes[0] << std::endl;
            std::cout.flush();
        } else if (next_node == -2) {
            // Invalid move, exit immediately
            return;
        } else {
            // Wrong answer, give up
            std::cout << "-1" << std::endl;
            std::cout.flush();
            return;
        }
    }
}

void play_game_as_Bob(int n) {
    char strategy;
    int start_node;

    std::cin >> strategy >> start_node;

    // Choose the strategy for Bob based on Alice's strategy
    char bob_strategy = (strategy == 'I') ? 'D' : 'I';
    int current_node = start_node;

    while (true) {
        std::cout << current_node << std::endl;
        std::cout.flush();

        int next_node;
        std::cin >> next_node;

        if (next_node == -1) {
            // Judge has no legal moves left, Bob wins
            break;
        }

        current_node = next_node;
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        // Read the edge weights matrix
        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> a[i][j];
            }
        }

        play_game_as_Alice(n, a);
        play_game_as_Bob(n);
    }

    return 0;
}