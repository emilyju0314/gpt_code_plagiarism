#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long

LL f(LL n) { //全ての桁の数の和
    LL res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

double g(LL n) {
    return (double)n/f(n);
}

int main(){
    vector<LL> res;
    LL base = 1;

    //　まずは候補を(1~150)99999 的な奴を全列挙
    for(int i = 0; i < 15; ++i) {
        for(int j = 1; j < 150; ++j) {
            res.push_back(base * (j+1) - 1);
        }
        base *= 10;
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    // ダメな奴を除く:
    for(LL i = 0; i < res.size(); ++i) {
        for(LL j = i+1; j < res.size(); ++j) {
            if(g(res[i]) > g(res[j])) {
                res.erase(res.begin() + i--);
                break;
            }
        }
    }

    LL k;
    cin >> k;
    for(LL i = 0; i < k; ++i) {
        cout << res[i] << endl;
    }
}