#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> getDivisors(int x) {
    std::vector<int> divisors;
    for(int i = 1; i <= x; i++) {
        if(x % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

std::vector<int> functionF(std::vector<int> a) {
    std::vector<int> result;
    for(int num : a) {
        std::vector<int> divisors = getDivisors(num);
        for(int d : divisors) {
            result.push_back(d);
        }
    }
    return result;
}

int main() {
    long long X, k;
    std::cin >> X >> k;
    
    std::unordered_set<int> seen;
    std::vector<int> currentSeq = {X};
    seen.insert(X);
    
    for(int i = 0; i < k; i++) {
        std::vector<int> nextSeq = functionF(currentSeq);
        
        bool foundRepeat = false;
        for(int num : nextSeq) {
            if(seen.count(num)) {
                foundRepeat = true;
                break;
            }
            seen.insert(num);
        }
        
        if(foundRepeat) {
            break;
        } else {
            currentSeq = nextSeq;
        }
    }
    
    int limit = std::min((int)currentSeq.size(), 105);
    for(int i = 0; i < limit; i++) {
        std::cout << currentSeq[i] << " ";
    }
    
    return 0;
}