#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int A, B, Q;
    std::cin >> A >> B >> Q;

    std::vector<long long> shrine_distances(A);
    std::vector<long long> temple_distances(B);
    for(int i = 0; i < A; i++) {
        std::cin >> shrine_distances[i];
    }
    for(int i = 0; i < B; i++) {
        std::cin >> temple_distances[i];
    }

    for(int i = 0; i < Q; i++) {
        long long x;
        std::cin >> x;

        long long min_distance = LLONG_MAX;

        for(int j = 0; j < A; j++) {
            auto shrine_it = std::lower_bound(shrine_distances.begin(), shrine_distances.end(), x);
            long long shrine_to_x = shrine_it - shrine_distances.begin() < A ? *shrine_it - x : LLONG_MAX;
            
            for(int k = 0; k < B; k++) {
                auto temple_it = std::lower_bound(temple_distances.begin(), temple_distances.end(), shrine_distances[j]);
                long long total_distance = std::max(shrine_to_x, std::max(shrine_distances[j] - x, *temple_it - shrine_distances[j]));
                min_distance = std::min(min_distance, total_distance);

                if(temple_it != temple_distances.begin()) {
                    --temple_it;
                    total_distance = std::max(shrine_to_x, std::max(shrine_distances[j] - x, shrine_distances[j] - *temple_it));
                    min_distance = std::min(min_distance, total_distance);
                }
            }
        }

        std::cout << min_distance << std::endl;
    }

    return 0;
}