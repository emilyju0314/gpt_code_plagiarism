#include <iostream>
#include <vector>

void query(int a, int b) {
    std::cout << "? " << a << " " << b << std::endl;
    std::cout.flush();
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> order(N);

    query(1, 2);
    int dist1_2;
    std::cin >> dist1_2;

    query(2, 3);
    int dist2_3;
    std::cin >> dist2_3;

    query(1, 3);
    int dist1_3;
    std::cin >> dist1_3;

    if (dist1_2 + dist2_3 == dist1_3) {
        order[0] = 2;
        order[1] = 3;
        order[2] = 1;
    } else if (dist1_2 + dist1_3 == dist2_3) {
        order[0] = 1;
        order[1] = 3;
        order[2] = 2;
    } else {
        order[0] = 1;
        order[1] = 2;
        order[2] = 3;
    }

    std::cout << "! ";
    for (int i = 0; i < N; i++) {
        std::cout << order[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}