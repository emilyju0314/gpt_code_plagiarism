#include <iostream>
#include <vector>

int main() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    // Initialize the molecule positions
    std::vector<int> positions(N);
    for(int i = 0; i < N; i++) {
        positions[i] = i + 1;
    }

    // Perform the molecule swapping operations
    for(int i = 0; i < K; i++) {
        int a, b;
        std::cin >> a >> b;
        std::swap(positions[a-1], positions[b-1]);
    }

    // Answer the queries
    for(int i = 0; i < Q; i++) {
        int query_type, s, t, x;
        std::cin >> query_type >> s >> t >> x;

        if(query_type == 1) {
            // Find the position of x after operations from s to t
            for(int j = s-1; j < t; j++) {
                if(positions[j] == x) {
                    x = j + 1;
                    break;
                } else if(positions[j] == x) {
                    x = j + 1;
                    break;
                }
            }
        } else if(query_type == 2) {
            // Find the number at position x after operations from s to t
            int target_position;
            for(int j = s-1; j < t; j++) {
                if(positions[j] == x) {
                    target_position = j + 1;
                    break;
                }
            }
            x = positions[target_position - 1];
        }
        std::cout << x << std::endl;
    }

    return 0;
}