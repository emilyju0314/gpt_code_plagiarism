#include <iostream>
#include <vector>

using namespace std;

int insertion_sort(vector<int>& a) {
    int n = a.size();
    int swaps = 0;
    
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j] < a[j - 1]) {
            swap(a[j], a[j - 1]);
            swaps++;
            j = j - 1;
        }
    }
    
    return swaps;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    
    int min_swaps = n*n; // initialize with a large value
    int min_swaps_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> temp = permutation; // create a copy of the permutation
            swap(temp[i], temp[j]); // try swapping elements at index i and j
            int swaps = insertion_sort(temp); // count number of swaps needed to sort the modified permutation
            
            if (swaps < min_swaps) {
                min_swaps = swaps;
                min_swaps_count = 1;
            } else if (swaps == min_swaps) {
                min_swaps_count++;
            }
        }
    }
    
    cout << min_swaps << " " << min_swaps_count << endl;
    
    return 0;
}