#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

bitset<5> rev(bitset<5> a){
    bitset<5> b;
    for(int i=0; i<5; ++i)
        b[i] = a[4-i];
    return b;
}
int rev(int a){
    int b = 0;
    for(int i=0; i<5; ++i){
        b <<= 1;
        if(a & (1<<i))
            b |= 1;
    }
    return b;
}

int solve(vector<int>& num, bitset<10> used, bitset<25> select, set<int>& result)
{
    if(select.to_ulong() == 15426462){
        select = ~select;
        select = ~select;
    }

    if(used.count() == 5){
        for(int i=0; i<5; ++i){
            bitset<5> a;
            for(int j=0; j<5; ++j)
                a[j] = !select[j*5+i];
            bitset<5> b = rev(a);
            if(b.to_ulong() < a.to_ulong())
                a = b;

            vector<int>::iterator it = num.begin();
            for(;;){
                it = find(it, num.end(), a.to_ulong());
                if(it == num.end())
                    return 0;
                if(!used[it-num.begin()]){
                    used[it-num.begin()] = true;
                    break;
                }
                ++ it;
            }
        }

        bool ok = true;
        bitset<25> a = select;
        for(int i=0; i<2; ++i){
            if(result.find(a.to_ulong()) != result.end()){
                ok = false;
                break;
            }
            // rotated
            for(int j=0; j<3; ++j){
                bitset<25> b = 0;
                for(int y=0; y<5; ++y){
                    for(int x=0; x<5; ++x){
                        b[5*x+4-y] = !a[5*y+x];
                    }
                }
                a = b;
                if(result.find(a.to_ulong()) != result.end()){
                    ok = false;
                    break;
                }
            }
            // mirror
            if(i == 0){
                bitset<25> b = 0;
                for(int y=0; y<5; ++y){
                    for(int x=0; x<5; ++x){
                        b[5*y+4-x] = a[5*y+x];
                    }
                }
                a = b;
            }
        }

        if(ok){
            result.insert(select.to_ulong());
            return 1;
        }else
            return 0;
    }

    int ret = 0;
    for(int i=0; i<10; ++i){
        if(used[i])
            continue;
        used[i] = true;

        bitset<25> tmp = select << 5;
        tmp |= num[i];
        ret += solve(num, used, tmp, result);

        tmp = select << 5;
        tmp |= rev(num[i]);
        ret += solve(num, used, tmp, result);

        used[i] = false;
    }
    return ret;
}

int main()
{
    for(;;){
        vector<int> num(10);
        for(int i=0; i<10; ++i){
            string s;
            cin >> s;
            if(s == "END")
                return 0;
            string s1 = s;
            reverse(s1.begin(), s1.end());
            s = min(s, s1);
            num[i] = bitset<5>(s).to_ulong();
        }
        sort(num.begin(), num.end());

        bitset<10> used;
        set<int> result;
        cout << solve(num, 0, 0, result) << endl;
    }
}