#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());

    std::vector<int> q;
    for (int i = 0; i < N/2 - 1; i++) {
        q.push_back(p[i]);
        q.push_back(p[N-1-i]);
    }

    // Special handling for the last two elements
    if (p[N/2 - 1] < p[N/2]) {
        q.push_back(p[N/2 - 1]);
        q.push_back(p[N/2]);
    } else {
        q.push_back(p[N/2]);
        q.push_back(p[N/2 - 1]);
    }

    for (int i = 0; i < N; i++) {
        std::cout << q[i] << " ";
    }

    return 0;
}