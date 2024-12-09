#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<set<int>> sets(N);
    vector<int> sizes(N);

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        sizes[i] = K;
        for (int j = 0; j < K; j++) {
            int num;
            cin >> num;
            sets[i].insert(num); 
        }
    }

    int maxProduct = 0;

    for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
        set<int> intersection, unionSet;

        for (int i = 0; i < N; i++) {
            if (bitmask & (1 << i)) {
                for (int num : sets[i]) {
                    unionSet.insert(num);
                    if (intersection.count(num) > 0) {
                        intersection.erase(num);
                    } else {
                        intersection.insert(num);
                    }
                }
            }
        }

        int product = unionSet.size() * intersection.size();
        maxProduct = max(maxProduct, product);
    }

    cout << maxProduct << endl;

    return 0;
}