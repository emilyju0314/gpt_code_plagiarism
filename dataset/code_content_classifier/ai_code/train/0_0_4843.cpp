#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int w;
    int v;
    double density;
};

bool compareItems(const Item &a, const Item &b) {
    return a.density > b.density;
}

int main() {
    int N, W;
    std::cin >> N >> W;
    
    std::vector<Item> items(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> items[i].w >> items[i].v;
        items[i].density = double(items[i].v) / items[i].w;
    }
    
    std::sort(items.begin(), items.end(), compareItems);
    
    double totalValue = 0.0;
    
    for(int i = 0; i < N; i++) {
        if(W == 0) break;
        
        int weightToTake = std::min(W, items[i].w);
        totalValue += weightToTake * items[i].density;
        W -= weightToTake;
    }
    
    std::cout << std::fixed << std::setprecision(6) << totalValue << std::endl;
    
    return 0;
}