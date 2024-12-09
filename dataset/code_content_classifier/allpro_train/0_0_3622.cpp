#include <iostream>
#include <set>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::set<int> colors;

    colors.insert(a);
    colors.insert(b);
    colors.insert(c);

    std::cout << colors.size() << std::endl;

    return 0;
}