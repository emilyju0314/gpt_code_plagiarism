#include <iostream>

int main() {
    int Q;
    std::cin >> Q;

    for(int i=0; i<Q; i++) {
        int N, count = 0;
        std::cin >> N;
        
        for(int j=2; j<=N; j++) {
            int total = 1;
            for(int k=1; k<=j/2; k++) {
                if(j % k == 0 && k != j) {
                    total *= k;
                }
            }
            if(total > 2*j) {
                count++;
            }
        }
        std::cout << count << std::endl;
    }

    return 0;
}