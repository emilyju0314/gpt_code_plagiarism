#include <iostream>
#include <vector>
#include <cmath>

struct Member {
    std::vector<std::pair<int, int>> route;
    std::vector<std::pair<int, int>> vocal_parts;
};

double calculate_time_focused(int cx, int cy, const Member& member) {
    double max_time_focused = 0.0;
    for (const auto& part : member.vocal_parts) {
        int start_time = part.first;
        int end_time = part.second;
        double start_angle = atan2(member.route[start_time].second - cy, member.route[start_time].first - cx);
        double end_angle = atan2(member.route[end_time].second - cy, member.route[end_time].first - cx);
        if (start_angle == end_angle) {
            max_time_focused += end_time - start_time;
        }
    }
    return max_time_focused;
}

int main() {
    int N;
    while (true) {
        std::cin >> N;
        if (N == 0) break;

        int cx, cy;
        std::cin >> cx >> cy;

        std::vector<Member> members(N);
        for (int i = 0; i < N; i++) {
            int M;
            std::cin >> M;
            members[i].route.resize(M);
            for (int j = 0; j < M; j++) {
                int x, y, t;
                std::cin >> x >> y >> t;
                members[i].route[j] = {x, y};
            }

            int L;
            std::cin >> L;
            members[i].vocal_parts.resize(L);
            for (int j = 0; j < L; j++) {
                int b, e;
                std::cin >> b >> e;
                members[i].vocal_parts[j] = {b, e};
            }
        }

        double max_time = 0.0;
        for (const auto& member : members) {
            max_time = std::max(max_time, calculate_time_focused(cx, cy, member));
        }

        std::cout.precision(10);
        std::cout << max_time << std::endl;
    }

    return 0;
}