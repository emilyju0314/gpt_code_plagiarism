#include <iostream>
#include <vector>
#include <algorithm>

struct Warehouse {
    int number;
    int distance;
    int numSenryobako;
};

bool compareWarehouse(Warehouse a, Warehouse b) {
    return a.distance < b.distance;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Warehouse> warehouses(n);
    for (int i = 0; i < n; i++) {
        std::cin >> warehouses[i].number >> warehouses[i].distance >> warehouses[i].numSenryobako;
    }
    
    std::sort(warehouses.begin(), warehouses.end(), compareWarehouse);
    
    for (int i = 0; i < n; i++) {
        std::cout << warehouses[i].number << " ";
    }
    
    return 0;
}