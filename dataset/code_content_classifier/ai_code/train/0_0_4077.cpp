#include <iostream>
#include <vector>

using namespace std;

int countDivisors(int x) {
    int count = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            count++;
            if(i * i != x) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> queries;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        queries.push_back(make_pair(x, y));
    }

    for(int i = 0; i < n; i++) {
        int x = queries[i].first;
        int y = queries[i].second;

        if(y == 0) {
            cout << countDivisors(x) << endl;
        } else {
            int ans = 0;
            for(int j = 1; j * j <= x; j++) {
                if(x % j == 0) {
                    bool divides = false;
                    for(int k = 1; k <= y; k++) {
                        if((x - k) % j == 0) {
                            divides = true;
                            break;
                        }
                    }
                    if(!divides) {
                        ans++;
                    }
                    
                    if(j * j != x) {
                        int otherDivisor = x / j;
                        divides = false;
                        for(int k = 1; k <= y; k++) {
                            if((x - k) % otherDivisor == 0) {
                                divides = true;
                                break;
                            }
                        }
                        if(!divides) {
                            ans++;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}