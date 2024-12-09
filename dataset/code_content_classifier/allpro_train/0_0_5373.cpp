#include <iostream>
#include <vector>

std::string F[205];
std::vector<std::string> A[205];

void calculate_F(int n) {
    F[0] = "0";
    F[1] = "1";
    
    for(int i = 2; i <= n; i++) {
        F[i] = F[i - 2] + F[i - 1];
    }
}

void calculate_A(int n) {
    A[1].push_back("0");
    A[2].push_back("1");
    
    for(int i = 3; i <= n; i++) {
        A[i].push_back("0");
        A[i].push_back(F[i]);
        
        for(int j = 2; j <= i; j++) {
            A[i].push_back(F[i].substr(j - 1));
        }
    }
}

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;
    
    calculate_F(n);
    calculate_A(n);
    
    std::cout << (A[n][k].length() >= m ? A[n][k].substr(0, m) : A[n][k]) << std::endl;
    
    return 0;
}