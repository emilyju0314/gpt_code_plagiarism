#include <iostream>
#include <vector>
#include <unordered_set>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_valid_move(int k, std::unordered_set<int>& forbidden_moves) {
    if (k == 1 || forbidden_moves.count(k) > 0) return false;
    if (k == 2 || is_prime(k)) return true;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0 && is_prime(i) && is_prime(k / i)) return true;
    }
    return false;
}

int main() {
    int n, f;
    std::cin >> n >> f;

    std::unordered_set<int> forbidden_moves;
    forbidden_moves.insert(f);

    std::vector<std::vector<int>> rows(n, std::vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> rows[i][j];
        }
    }

    bool alice_start_wins = false;
    bool bob_start_wins = false;

    for (int i = 1; i <= 2 * 10^5; ++i) {
        if (!is_valid_move(i, forbidden_moves)) continue;

        bool alice_wins = true;
        bool bob_wins = true;

        for (int j = 0; j < n; ++j) {
            int dist_to_right = rows[j][2] - rows[j][1];
            int dist_to_left = rows[j][1] - rows[j][0];
            
            if ((dist_to_right % i == 0 || dist_to_left % i == 0) && 
                dist_to_left <= i && dist_to_right <= i) {
                if (dist_to_right % i == 0 && dist_to_left % i == 0) {
                    bob_wins = false;
                } else if (dist_to_left % i == 0) {
                    bob_wins = false;
                } else {
                    alice_wins = false;
                }
            } else {
                if (dist_to_right % i == 0) {
                    bob_wins = false;
                } else if (dist_to_left % i == 0) {
                    alice_wins = false;
                }
            }
        }

        if (alice_wins) alice_start_wins = true;
        if (bob_wins) bob_start_wins = true;
    }

    if (alice_start_wins) std::cout << "Alice\n";
    else std::cout << "Bob\n";

    if (bob_start_wins) std::cout << "Alice\n";
    else std::cout << "Bob\n";

    return 0;
}