#include <iostream>
#include <vector>
#include <algorithm>

struct Armor {
    int type;
    long long weight;
    long long defense;
};

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;
    
    std::vector<Armor> armors(N);
    for(int i = 0; i < N; i++) {
        std::cin >> armors[i].type >> armors[i].weight >> armors[i].defense;
    }
    
    bool skillActivated = false;
    
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            long long totalWeight = 0, totalDefense = 0;
            for(int k = i; k <= j; k++) {
                totalWeight += armors[k].weight;
                totalDefense += armors[k].defense;
            }
            if(totalWeight >= A && totalWeight <= B && totalDefense >= A && totalDefense <= B) {
                skillActivated = true;
                break;
            }
        }
        if(skillActivated) {
            break;
        }
    }
    
    if(skillActivated) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}