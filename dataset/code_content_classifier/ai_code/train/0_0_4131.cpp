#include <iostream>
#include <cmath>

using namespace std;

long long n;

bool check(long long k) {
    long long vasyaCandies = 0, petyaCandies = 0;
    long long remainingCandies = n;
    
    while (remainingCandies > 0) {
        long long eatenByVasya = min(k, remainingCandies);
        vasyaCandies += eatenByVasya;
        remainingCandies -= eatenByVasya;
        
        long long eatenByPetya = min(remainingCandies / 10, (long long)floor(remainingCandies * 0.1));
        petyaCandies += eatenByPetya;
        remainingCandies -= eatenByPetya;
    }
    
    return vasyaCandies >= (n + 1) / 2;
}

int main() {
    cin >> n;
    
    long long left = 1, right = n, ans = n;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}