#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    int X, Y, Z;
    std::cin >> X;
    std::set<int> organizationA;
    for (int i = 0; i < X; i++) {
        int a;
        std::cin >> a;
        organizationA.insert(a);
    }

    std::cin >> Y;
    std::set<int> organizationB;
    for (int i = 0; i < Y; i++) {
        int b;
        std::cin >> b;
        organizationB.insert(b);
    }

    std::cin >> Z;
    std::set<int> productC;
    for (int i = 0; i < Z; i++) {
        int c;
        std::cin >> c;
        productC.insert(c);
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if ((organizationA.find(i) == organizationA.end() && productC.find(i) != productC.end()) ||
            (organizationB.find(i) != organizationB.end() && productC.find(i) != productC.end())) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}