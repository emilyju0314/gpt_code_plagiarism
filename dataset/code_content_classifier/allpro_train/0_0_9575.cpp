#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> leftHints(n+1, 0);
    std::vector<int> rightHints(n+1, 0);

    for(int i = 0; i < m; i++){
        std::string direction;
        int boxNum;
        std::cin >> direction >> boxNum;

        if(direction == "To the left of"){
            leftHints[boxNum] = 1;
        } else {
            rightHints[boxNum] = 1;
        }
    }

    int checkCount = 0;
    for(int i = 1; i <= n; i++){
        if((leftHints[i] && rightHints[i]) || (leftHints[i-1] && rightHints[i])){
            std::cout << -1 << std::endl;
            return 0;
        }

        if(leftHints[i] || rightHints[i]){
            checkCount++;
        }
    }

    std::cout << checkCount << std::endl;

    return 0;
}