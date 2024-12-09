#include <iostream>
#include <algorithm>

bool isPropertyHold(int x, int p1, int p2, int p3, int p4) {
    int f1 = x % p1;
    int f2 = f1 % p2;
    int f3 = f2 % p3;
    int f4 = f3 % p4;
    
    return f1 == x || f2 == x || f3 == x || f4 == x;
}

int main() {
    int p1, p2, p3, p4, a, b;
    std::cin >> p1 >> p2 >> p3 >> p4 >> a >> b;

    int count = 0;
    
    for (int x = a; x <= b; x++) {
        int cnt = 0;
        int arr[] = {p1, p2, p3, p4};
        do {
            if (isPropertyHold(x, arr[0], arr[1], arr[2], arr[3])) {
                cnt++;
            }
        } while (std::next_permutation(arr, arr+4));
        
        if (cnt >= 7) {
            count++;
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}