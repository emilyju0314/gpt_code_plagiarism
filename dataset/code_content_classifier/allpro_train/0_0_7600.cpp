#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;
    
    std::set<int> mochis;
    
    for(int i = 0; i < N; i++) {
        int d;
        std::cin >> d;
        mochis.insert(d);
    }
    
    std::cout << mochis.size() << std::endl;
    
    return 0;
}