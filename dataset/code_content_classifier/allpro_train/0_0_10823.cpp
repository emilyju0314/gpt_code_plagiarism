#include <iostream>
#include <vector>
#include <unordered_map>

bool isMatching(std::vector<int>& q, std::vector<int>& p) {
    std::unordered_map<int, int> idx;
    for (int i = 0; i < p.size(); i++) {
        idx[p[i]] = i;
    }

    int run = 1;
    bool increasing = q[0] < q[1];

    for (int i = 1; i < q.size(); i++) {
        if ((q[i] < q[i - 1]) != increasing) { 
            run++;
            increasing = !increasing;
        }
        if (idx[q[i]] < idx[q[i-1]]) {
            return false;
        }
    }

    return run == 3;
}

int main() {
    int N, M;
    std::cin >> N;
    std::vector<int> q(N);
    for (int i = 0; i < N; i++) {
        std::cin >> q[i];
    }

    std::cin >> M;
    std::vector<int> p(M);
    for (int i = 0; i < M; i++) {
        std::cin >> p[i];
    }

    if (isMatching(q, p)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}