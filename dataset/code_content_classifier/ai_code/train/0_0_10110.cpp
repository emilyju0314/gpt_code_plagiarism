#include <iostream>
#include <set>
#include <string>

int main() {
    int N;
    std::cin >> N;
    
    std::set<std::string> kinds;

    for (int i = 0; i < N; i++) {
        std::string item;
        std::cin >> item;
        kinds.insert(item);
    }

    std::cout << kinds.size() << std::endl;

    return 0;
}