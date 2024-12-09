#include <iostream>
#include <string>

std::string f(int A, int B) {
    std::string result;
    while (A > 0 || B > 0) {
        if (A > B) {
            int len = std::min(2, A);
            result += std::string(len, 'A');
            A -= len;
        } else {
            int len = std::min(2, B);
            result += std::string(len, 'B');
            B -= len;
        }
    }
    return result;
}

int main() {
    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int A, B, C, D;
        std::cin >> A >> B >> C >> D;
        std::string str = f(A, B).substr(C-1, D-C+1);
        std::cout << str << std::endl;
    }

    return 0;
}