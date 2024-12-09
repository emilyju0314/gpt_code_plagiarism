#include <iostream>
#include <string>

int main() {
    int n;
    std::string colors;

    // Input number of cockroaches
    std::cin >> n;

    // Input colors of cockroaches
    std::cin >> colors;

    int count1 = 0, count2 = 0;

    // Count number of turns needed to make colors alternate
    for(int i=0; i<n; i++) {
        if(i % 2 == 0) {
            if(colors[i] == 'r') {
                count1++;
            } else {
                count2++;
            }
        } else {
            if(colors[i] == 'r') {
                count2++;
            } else {
                count1++;
            }
        }
    }

    // Output the minimum number of turns needed
    std::cout << std::min(count1, count2) << std::endl;

    return 0;
}