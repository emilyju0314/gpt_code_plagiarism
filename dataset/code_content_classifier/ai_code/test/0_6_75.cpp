#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int left = 0, right = N - 1;
    int last = 0;
    std::string winner = "Alice"; // Assuming Alice wins by default
    
    while(left <= right) {
        if(A[left] > last && A[right] > last) {
            if(A[left] < A[right]) {
                last = A[left];
                left++;
            } else {
                last = A[right];
                right--;
            }
        } else if(A[left] > last) {
            last = A[left];
            left++;
        } else if(A[right] > last) {
            last = A[right];
            right--;
        } else {
            break;
        }
        
        winner = (winner == "Alice") ? "Bob" : "Alice";
    }
    
    std::cout << winner << std::endl;
    
    return 0;
}