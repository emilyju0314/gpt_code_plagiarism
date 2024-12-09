#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> strengths(n), bribes(n);
    int friend_index;

    for(int i = 0; i < n; i++) {
        std::cin >> bribes[i];
        if(bribes[i] == -1) {
            friend_index = i;
            strengths[i] = -1;
        } else {
            strengths[i] = i;
        }
    }

    std::sort(strengths.begin(), strengths.end(), [&](int a, int b) {
        return bribes[a] < bribes[b];
    });

    int result = 0;
    for(int i = 0; i < n; i += 2) {
        if(strengths[i] == friend_index || strengths[i + 1] == friend_index) {
            break;
        } else {
            result += bribes[strengths[i]];
        }
    }

    std::cout << result << std::endl;

    return 0;
}