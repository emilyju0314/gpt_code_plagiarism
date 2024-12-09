#include <iostream>

using namespace std;

long long getDistinctHeights(long long n) {
    long long heights = 0;
    
    for (long long height = 1; n >= (height * (height + 1) / 2); height++) {
        long long remainingCards = n - (height * (height + 1) / 2);
        if (remainingCards % (height + 1) == 0) {
            heights++;
        }
    }
    
    return heights;
}

int main() {
    long long n;
    cin >> n;
    
    cout << getDistinctHeights(n) << endl;
    
    return 0;
}