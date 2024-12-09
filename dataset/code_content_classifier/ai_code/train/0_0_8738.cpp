#include <iostream>
#include <map>

int main() {
    int N, Q;
    while (std::cin >> N >> Q) {
        if (N == 0 && Q == 0) {
            break;
        }

        std::map<int, std::pair<std::string, int>> database;

        for (int i = 0; i < N; i++) {
            std::string eraName;
            int eraBasedYear, westernYear;
            std::cin >> eraName >> eraBasedYear >> westernYear;
            for (int j = westernYear; j <= eraBasedYear; j++) {
                database[j] = std::make_pair(eraName, j - westernYear + 1);
            }
        }

        for (int i = 0; i < Q; i++) {
            int query;
            std::cin >> query;
            if (database.find(query) == database.end()) {
                std::cout << "Unknown" << std::endl;
            } else {
                std::cout << database[query].first << " " << database[query].second << std::endl;
            }
        }
    }

    return 0;
}