#include <iostream>
#include <vector>

void processQueries(std::vector<int>& permutation, std::vector<int>& queries) {
    for(int q : queries) {
        int pos;
        for(int i = 0; i < permutation.size(); i++) {
            if(permutation[i] == q) {
                pos = i;
                break;
            }
        }
        
        if(pos < permutation.size()/2) {
            for(int i = 0; i < pos; i++) {
                std::swap(permutation[i], permutation[(permutation.size()/2)+i]);
            }
        } else {
            for(int i = pos; i < permutation.size(); i++) {
                std::swap(permutation[i], permutation[i-permutation.size()/2]);
            }
        }
    }
}

int main() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> permutation(N);
    for(int i = 0; i < N; i++) {
        std::cin >> permutation[i];
    }
    
    std::vector<int> queries(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> queries[i];
    }
    
    processQueries(permutation, queries);
    
    for(int i = 0; i < N; i++) {
        std::cout << permutation[i] << " ";
    }
    
    return 0;
}