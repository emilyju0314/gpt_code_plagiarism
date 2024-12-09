#include <iostream>
#include <vector>

bool isComposite(int num) {
    if(num <= 3) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return true;
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        int sum = 0;
        std::vector<int> subset;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(isComposite(sum)) {
                subset.push_back(i+1);
                break;
            }
        }

        if(subset.empty()) {
            for(int i = 0; i < n-1; i++) {
                for(int j = i+1; j < n; j++) {
                    sum = arr[i] + arr[j];
                    if(isComposite(sum)) {
                        subset.push_back(i+1);
                        subset.push_back(j+1);
                        break;
                    }
                }
                if(!subset.empty()) break;
            }
        }

        std::cout << subset.size() << "\n";
        for(int ele : subset) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }

    return 0;
}