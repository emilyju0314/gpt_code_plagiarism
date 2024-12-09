#include <iostream>
#include <vector>

int main() {
    int N, T, Q;
    std::cin >> N >> T >> Q;

    std::vector<std::pair<int, int>> houses(N);
    for (int i = 0; i < N; i++) {
        int Ai, Di;
        std::cin >> Ai >> Di;
        houses[i] = {Ai, Di};
    }

    std::vector<int> important_people(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> important_people[i];
    }

    for (int i = 0; i < Q; i++) {
        int position = important_people[i];
        for (int j = 0; j < N; j++) {
            int Ai = houses[j].first;
            int Di = houses[j].second;

            if (Di == 1) {
                position += T;
            } else {
                position -= T;
            }

            if (position <= Ai) {
                position = Ai - (Ai - position) % (2 * (Ai - position));
            } else {
                position = Ai + (position - Ai) % (2 * (position - Ai));
            }
        }

        std::cout << position << std::endl;
    }

    return 0;
}