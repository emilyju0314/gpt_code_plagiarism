#include <iostream>
#include <vector>

bool is_primitive_root(int x, int p) {
    std::vector<int> powers(p - 1, 0);
    int curr = 1;
    for (int i = 1; i < p; i++) {
        curr = (curr * x) % p;
        if (curr == 1 || powers[curr - 1] != 0) {
            return false;
        }
        powers[curr - 1] = i;
    }
    return curr == 1;
}

int count_primitive_roots(int p) {
    int count = 0;
    for (int x = 2; x < p; x++) {
        if (is_primitive_root(x, p)) {
            count++;
        }
    }
    return count;
}

int main() {
    int p;
    std::cin >> p;
    
    int result = count_primitive_roots(p);
    std::cout << result << std::endl;
    
    return 0;
}