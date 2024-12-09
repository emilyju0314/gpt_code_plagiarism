#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    std::vector<int> a(n);

    for(int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<bool> visited(n, false);
    int total_cost = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            int next_room = a[i];
            while(next_room != i+1) {
                visited[next_room-1] = true;
                next_room = a[next_room-1];
            }
            total_cost += c[i];
        }
    }

    std::cout << total_cost << std::endl;

    return 0;
}