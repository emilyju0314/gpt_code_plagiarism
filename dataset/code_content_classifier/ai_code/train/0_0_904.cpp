#include <iostream>
#include <set>

int main() {
    int N, x, M, y;
    std::cin >> N >> x >> M >> y;

    std::set<int> partitions;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            int partition = i * y - j * x;
            partitions.insert(partition);
        }
    }

    std::cout << partitions.size() << std::endl;

    return 0;
}