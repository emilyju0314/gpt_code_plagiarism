#include <iostream>
#include <vector>

int main() {
    int K;
    std::cin >> K;

    std::vector<bool> visited(K, false);
    std::vector<int> mod(K, -1);
    std::vector<int> q(1, 0);
    mod[0] = 0;

    while (!q.empty()) {
        int a = q.back();
        q.pop_back();
        for (int d = 0; d <= 9; ++d) {
            int b = (a * 10 + d) % K;
            if (mod[b] == -1) {
                q.push_back(b);
                mod[b] = d;
                visited[b] = true;
            }
        }
    }

    for (int i = 1; i < K; ++i) {
        if (visited[i]) {
            std::cout << mod[i] << std::endl;
            break;
        }
    }

    return 0;
}