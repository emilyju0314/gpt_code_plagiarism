#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Program {
    std::string name;
    int weekday;
    int start;
};

int main() {
    int N, P;
    while (std::cin >> N && N != 0) {
        std::vector<Program> programs(N);
        for (int i = 0; i < N; i++) {
            std::cin >> programs[i].name >> programs[i].weekday >> programs[i].start;
        }
        std::cin >> P;
        std::vector<std::string> favorites(P);
        for (int i = 0; i < P; i++) {
            std::cin >> favorites[i];
        }

        int maxProgramsWatched = 0;
        for (int i = 0; i < (1 << N); i++) {
            std::vector<Program> presentPrograms;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    presentPrograms.push_back(programs[j]);
                }
            }

            bool valid = true;
            for (const auto& fav : favorites) {
                bool found = false;
                for (const auto& p : presentPrograms) {
                    if (p.name == fav) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                int totalMinutes = 0;
                std::sort(presentPrograms.begin(), presentPrograms.end(), [](const Program& a, const Program& b){
                    return a.start < b.start;
                });
                for (int k = 0; k < presentPrograms.size(); k++) {
                    if (k == 0 || presentPrograms[k].start >= totalMinutes) {
                        totalMinutes = presentPrograms[k].start + 30;
                    } else {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    maxProgramsWatched = std::max(maxProgramsWatched, (int)presentPrograms.size());
                }
            }
        }

        if (maxProgramsWatched == 0) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << maxProgramsWatched << std::endl;
        }
    }

    return 0;
}