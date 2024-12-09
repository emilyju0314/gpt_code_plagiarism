#include <iostream>
#include <stack>

int main() {
    std::stack<int> cars;

    int num;
    while (std::cin >> num) {
        if (num == 0) {
            std::cout << cars.top() << std::endl;
            cars.pop();
        } else {
            cars.push(num);
        }
    }

    return 0;
}