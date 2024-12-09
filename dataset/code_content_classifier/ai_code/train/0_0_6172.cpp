#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<int, int>> seats(k);
    std::unordered_set<int> chosen_seats;

    for (int i = 0; i < k; i++) {
        int row, seat;
        std::cin >> row >> seat;
        seats[i] = std::make_pair(row, seat);
        chosen_seats.insert(row * m + seat);
    }

    int row = 1, seat = 1;
    for (int i = 0; i < k; i++) {
        if (chosen_seats.find(row * m + seat) != chosen_seats.end()) {
            seat++;
            if (seat > m) {
                seat = 1;
                row++;
            }
        }
        std::cout << row << " " << seat << std::endl;
        seat++;
        if (seat > m) {
            seat = 1;
            row++;
        }
    }

    return 0;
}