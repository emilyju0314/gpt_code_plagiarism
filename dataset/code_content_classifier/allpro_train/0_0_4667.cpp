#include <iostream>
#include <vector>
#include <unordered_set>

std::string playGame(int n, std::vector<std::pair<int, std::string>> elements) {
    // Initialize a set for the elements
    std::unordered_set<int> set;

    // Convert pi-ary numbers to decimal and add them to the set
    for(auto element : elements) {
        int p = element.first;
        std::string m = element.second;

        long long decimalValue = 0;
        for(int i = 0; i < m.size(); i++) {
            decimalValue = decimalValue * p;
            if(m[i] >= '0' && m[i] <= '9') {
                decimalValue += m[i] - '0';
            } else if(m[i] >= 'A' && m[i] <= 'Z') {
                decimalValue += m[i] - 'A' + 10;
            } else {
                decimalValue += m[i] - 'a' + 36;
            }
        }
        set.insert(decimalValue);
    }

    // Players take turns removing elements and subtracting integers until set is empty
    bool player1Turn = true;
    while(!set.empty()){
        if(player1Turn) {
            // Player 1 removes elements and adds modified ones
            std::unordered_set<int> newElements;
            for(int element : set) {
                while(element > 0) {
                    int remainder = element % 2;
                    while(element > 0 && remainder == 1) {
                        int count = 0;
                        while(element > 0 && remainder == 1) {
                            count++;
                            element /= 2;
                            remainder = element % 2;
                        }
                        newElements.insert(count);
                        count = 0;
                    }
                    element /= 2;
                    remainder = element % 2;
                }
            }
            set = newElements;
        } else {
            // Player 2 subtracts integers from an element
            int elementToSubtractFrom = *set.begin();
            set.erase(elementToSubtractFrom);
            for(int i = 1; i < elementToSubtractFrom; i++) {
                int newElement = elementToSubtractFrom - i;
                set.insert(newElement);
            }
        }
        player1Turn = !player1Turn;
    }

    // Check if player 1 wins
    return player1Turn ? "win" : "lose";
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, std::string>> elements;
    for(int i = 0; i < n; i++) {
        int p;
        std::string m;
        std::cin >> p >> m;
        elements.emplace_back(p, m);
    }

    std::string result = playGame(n, elements);
    std::cout << result << std::endl;

    return 0;
}