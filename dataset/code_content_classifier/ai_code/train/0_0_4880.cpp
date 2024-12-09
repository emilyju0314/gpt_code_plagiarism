#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> elements(2*n-1);

    for(int i = 0; i < 2*n-1; i++) {
        std::cin >> elements[i];
    }

    std::sort(elements.begin(), elements.end());

    int sum = 0;

    for(int i = 0; i < 2*n-1; i++) {
        if(n > 1 && elements[i] < 0) {
            elements[i] = -elements[i];
            n--;
        }
        sum += elements[i];
    }

    std::cout << sum << std::endl;

    return 0;
} 

//input
//2
//50 50 50

//output
//150

//input
//2
//-1 -100 -1

//output
//100