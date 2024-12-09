#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> permutation;
    for(int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }

    int cntn = 1;
    for(int i = 1; i <= n; i++) {
        cntn *= i;
    }

    // Find the m-th lexicographically permutation of length n with maximum f(p)
    do {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (i + 1) * permutation[i];
        }
        if(sum == cntn) {
            m--;
            if(m == 0) {
                for(int i = 0; i < n; i++) {
                    cout << permutation[i] << " ";
                }
                break;
            }
        }
    } while(next_permutation(permutation.begin(), permutation.end()));

    return 0;
}