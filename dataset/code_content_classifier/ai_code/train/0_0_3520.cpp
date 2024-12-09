#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> notes(n);
    for(int i = 0; i < n; i++) {
        std::cin >> notes[i];
    }

    std::vector<int> rooms_visited(n + 1, 0);
    rooms_visited[0] = 1;

    int max_room = 1;
    for(int i = 0; i < n; i++) {
        rooms_visited[notes[i]] = 1;
        if(rooms_visited[i + 1] == 1) {
            max_room++;
        }
    }

    std::cout << max_room << std::endl;

    return 0;
}