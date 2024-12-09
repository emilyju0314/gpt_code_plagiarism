#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> scores(N);
    std::vector<int> leaders;
    std::vector<int> queries(Q);

    for (int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }

    for (int i = 0; i < Q; i++) {
        std::string query;
        int student_num;
        std::cin >> query;

        if (query == "ADD") {
            std::cin >> student_num;
            leaders.push_back(student_num);
        } else if (query == "REMOVE") {
            std::cin >> student_num;
            leaders.erase(std::remove(leaders.begin(), leaders.end(), student_num), leaders.end());
        } else if (query == "CHECK") {
            std::cin >> queries[i];
        }
    }

    for (int i = 0; i < Q; i++) {
        if (queries[i] == 0) {
            std::cout << "NA" << std::endl;
        } else {
            int min_r = INT_MAX;
            for (int r = 0; r <= 1000000000; r++) {
                int count = 0;
                for (int j = 0; j < N; j++) {
                    int leader_score = scores[j];
                    bool can_participate = false;
                    for (int leader : leaders) {
                        if (leader_score >= scores[leader - 1] - r) {
                            can_participate = true;
                            break;
                        }
                    }
                    if (!can_participate) {
                        count++;
                    }
                }
                if (count <= queries[i]) {
                    min_r = r;
                    break;
                }
            }
            std::cout << min_r << std::endl;
        }
    }

    return 0;
}