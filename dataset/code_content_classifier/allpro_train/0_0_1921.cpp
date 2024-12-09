#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ages(n);
    for(int i = 0; i < n; i++){
        cin >> ages[i];
    }

    map<int, long long> ageCount;
    for(int i = 0; i < n; i++){
        ageCount[ages[i]]++;
    }

    long long maxCoins = 0;
    for(int i = 0; i < n; i++){
        if(ages[i] == 0){
            maxCoins += ageCount[0];
        }
        else{
            maxCoins += ageCount[0] + ageCount[(1 << (31 - __builtin_clz(ages[i])))];
        }
    }

    cout << maxCoins << endl;

    return 0;
}