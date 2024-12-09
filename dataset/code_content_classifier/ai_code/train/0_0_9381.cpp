#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a, b, m, r0;
    std::cin >> a >> b >> m >> r0;

    std::vector<int> sequence;
    std::vector<int> position(m, -1);

    int r = r0;
    int index = 0;
    while (position[r] == -1) {
        position[r] = index;
        sequence.push_back(r);
        r = (a * r + b) % m;
        index++;
    }

    int period = sequence.size() - position[r];
    std::cout << period << std::endl;

    return 0;
}