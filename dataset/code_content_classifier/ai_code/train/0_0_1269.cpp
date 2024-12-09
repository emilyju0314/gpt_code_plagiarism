#include <iostream>
#include <vector>
#include <algorithm>

struct TShirt {
    int price;
    int quality;
};

bool compareTShirts(const TShirt& a, const TShirt& b) {
    if(a.quality != b.quality) {
        return a.quality > b.quality;
    } else {
        return a.price < b.price;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<TShirt> tshirts(n);
    for(int i = 0; i < n; i++) {
        std::cin >> tshirts[i].price >> tshirts[i].quality;
    }

    std::sort(tshirts.begin(), tshirts.end(), compareTShirts);

    int k;
    std::cin >> k;

    std::vector<int> customers(k);
    for(int i = 0; i < k; i++) {
        std::cin >> customers[i];
    }

    std::vector<int> result(k, 0);
    int currentTShirt = 0;

    for(int i = 0; i < k; i++) {
        int moneyLeft = customers[i];
        while(currentTShirt < n && moneyLeft >= tshirts[currentTShirt].price) {
            result[i]++;
            moneyLeft -= tshirts[currentTShirt].price;
            currentTShirt++;
        }
    }

    for(int i = 0; i < k; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}