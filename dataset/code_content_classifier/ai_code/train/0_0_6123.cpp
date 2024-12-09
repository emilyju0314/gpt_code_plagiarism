#include <iostream>
#include <unordered_map>

int main() {
    int s;
    std::cin >> s;

    std::unordered_map<int, int> index;
    index[s] = 1;

    int a = s;
    int i = 1;

    while (true) {
        i++;
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = 3 * a + 1;
        }

        if (index.find(a) != index.end()) {
            std::cout << i << std::endl;
            break; 
        }

        index[a] = i;
    }

    return 0;
}