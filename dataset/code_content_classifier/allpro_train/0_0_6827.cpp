#include <iostream>
#include <vector>
#include <algorithm>

struct Art {
    long long size;
    int value;
};

bool compare(Art a, Art b) {
    return a.size < b.size;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Art> arts(N);

    for(int i = 0; i < N; i++) {
        std::cin >> arts[i].size >> arts[i].value;
    }

    std::sort(arts.begin(), arts.end(), compare);

    long long sum = 0;
    long long max_diff = 0;

    for(int i = 0; i < N; i++) {
        sum += arts[i].value;
        long long diff = sum - arts[i].size;
        max_diff = std::max(max_diff, diff);
    }

    std::cout << max_diff << std::endl;

    return 0;
}