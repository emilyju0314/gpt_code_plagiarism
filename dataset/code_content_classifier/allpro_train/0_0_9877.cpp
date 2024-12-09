#include <iostream>
#include <vector>

using namespace std;

int smallestSubarraySize(int N, int S, vector<int> arr) {
    int result = INT_MAX;
    int sum = 0;
    int i = 0;
    
    for (int j = 0; j < N; j++) {
        sum += arr[j];
        
        while (sum >= S) {
            result = min(result, j - i + 1);
            sum -= arr[i];
            i++;
        }
    }
    
    return result == INT_MAX ? 0 : result;
}

int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int result = smallestSubarraySize(N, S, arr);
    cout << result << endl;
    
    return 0;
}