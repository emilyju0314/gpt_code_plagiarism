#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Leaf {
    std::string treeSpecies;
    std::string color;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Leaf> leaves;

    for(int i = 0; i < n; i++) {
        Leaf leaf;
        std::cin >> leaf.treeSpecies >> leaf.color;
        
        bool exists = false;
        for(const Leaf& l : leaves) {
            if(leaf.treeSpecies == l.treeSpecies && leaf.color == l.color) {
                exists = true;
                break;
            }
        }

        if(!exists) {
            leaves.push_back(leaf);
        }
    }

    std::cout << leaves.size() << std::endl;

    return 0;
}