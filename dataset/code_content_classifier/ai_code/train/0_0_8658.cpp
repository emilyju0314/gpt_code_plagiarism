#include <iostream>
#include <vector>

int main() {
    int M, N;
    std::cin >> M >> N;
    
    std::vector<int> days(N);
    for(int i = 0; i < N; i++) {
        std::cin >> days[i];
    }
    
    int changes = 0;
    
    for(int i = 1; i < N; i++) {
        if(days[i] == days[i-1]) {
            changes++;
            if(i != N-1 && days[i] == days[i+1]) {
                days[i] = (days[i] % M) + 1;
            } else {
                for(int j = 1; j <= M; j++) {
                    if(j != days[i-1] && (i == N-1 || j != days[i+1])) {
                        days[i] = j;
                        break;
                    }
                }
                changes++;
            }
        }
    }
    
    std::cout << changes << std::endl;
    
    return 0;
}