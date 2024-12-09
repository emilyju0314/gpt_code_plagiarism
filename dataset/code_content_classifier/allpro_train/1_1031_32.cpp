#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(1){
        int h,w,cnum,sp;
        cin >> h;
        if(h == 0) break;
        cin >> cnum >> w >> sp;
        vector<string> str;
        string s;
        getline(cin, s);
        while(getline(cin, s), s!="?"){
            str.push_back(s);
        }
        
        vector<string> fstr;
        for(auto s: str){
            int len = s.length();
            if(len == 0) len++;
            s += string(w, '.');
            for(int i=0; i<len; i+=w){
                fstr.push_back(s.substr(i, w));
            }
        }

        int page = (fstr.size() +h*cnum -1) /(h*cnum);
        for(int i=0; i<h*cnum; i++){
            fstr.emplace_back(w, '.');
        }

        for(int i=0; i<page; i++){
            for(int j=0; j<h; j++){
                string s = "";
                for(int k=0; k<cnum; k++){
                    if(k != 0){
                        s += string(sp, '.');
                    }
                    s += fstr[i*h*cnum +k*h +j];
                }
                cout << s << endl;
            }
            cout << "#" << endl;
        }
        cout << "?" << endl;
    }
    return 0;
}
