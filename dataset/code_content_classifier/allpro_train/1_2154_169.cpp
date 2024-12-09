#include <bits/stdc++.h>
using namespace std;

int main(){
    double num;

    while(cin >> num, num >= 0){
        long long tmp = (long long)num;

        string ans = "";
        stack<char> st;
        for(int i = 0;i < 8;i++){
            st.push((tmp % 2) + '0');
            tmp /= 2;
        }

        if(tmp != 0){
            cout << "NA" << endl;
            continue;
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        double t2 = num - (long long)num;

        ans.push_back('.');

        for(int i = 0;i < 4;i++){
            t2 *= 2;
            if(t2 >= 1){
                ans.push_back('1');
                t2 -= 1;
            }else{
                ans.push_back('0');
            }
        }

        if(t2 > 0){
            cout << "NA" << endl;
            continue;
        }

        cout << ans << endl;

    }

    return 0;
}



