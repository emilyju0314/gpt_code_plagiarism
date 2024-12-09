#include <iostream>
#include <vector>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::vector<int> beautifulSeq;
    
    if (abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - d) <= 1) {
        while (a > 0 || b > 0 || c > 0 || d > 0) {
            if (a > 0) {
                beautifulSeq.push_back(0);
                a--;
            }
            if (b > 0) {
                beautifulSeq.push_back(1);
                b--;
            }
            if (c > 0) {
                beautifulSeq.push_back(2);
                c--;
            }
            if (d > 0) {
                beautifulSeq.push_back(3);
                d--;
            }
        }

        std::cout << "YES" << std::endl;
        for (int num : beautifulSeq) {
            std::cout << num << " ";
        }
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}