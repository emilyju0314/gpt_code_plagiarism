#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::queue<int> cache;
    std::unordered_set<int> cacheSet;

    for (int i = 0; i < N; i++) {
        int ID;
        std::cin >> ID;

        // Check if ID is already in cache
        if (cacheSet.count(ID) > 0) {
            // Remove ID from current position
            std::queue<int> temp;
            while (cache.front() != ID) {
                temp.push(cache.front());
                cache.pop();
            }
            cache.pop();

            // Restore original order
            while (!temp.empty()) {
                cache.push(temp.front());
                temp.pop();
            }
        } else {
            // If cache is full, remove least recently accessed item
            if (cache.size() == M) {
                cacheSet.erase(cache.front());
                cache.pop();
            }
        }

        // Add ID to cache
        cache.push(ID);
        cacheSet.insert(ID);
    }

    // Print remaining IDs in cache
    while (!cache.empty()) {
        std::cout << cache.front() << std::endl;
        cache.pop();
    }

    return 0;
}